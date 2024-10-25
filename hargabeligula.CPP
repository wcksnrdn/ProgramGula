#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <time.h>

int main() {

    const double hargaPerKg = 13500;
    printf("Pembelian Gula\n");
    printf("Harga per kilogram gula: Rp %.2f\n\n", hargaPerKg);

    char nama[100];
    char email[100];
    char tanggal[20];
    char jam[20]; // Menambahkan variabel untuk jam pembelian
    cout << "Nama Pembeli : ";
    gets(nama);
    cout << "Gmail : ";
    gets(email);

    // Mengambil tanggal dan jam hari ini
    time_t now = time(0);
    struct tm *localtm = localtime(&now);
    sprintf(tanggal, "%02d/%02d/%d", localtm->tm_mday, localtm->tm_mon + 1, localtm->tm_year + 1900);
    sprintf(jam, "%02d:%02d:%02d", localtm->tm_hour, localtm->tm_min, localtm->tm_sec);

    double beratGula;
    printf("Masukkan berat gula (kg): ");
    scanf("%lf", &beratGula);

    double diskon = 0;
    double pajak = 0;
    double totalDiskon = 0;
    double totalPajak = 0;

    if (beratGula < 15) {
        pajak = 0.01;
        totalPajak = hargaPerKg * beratGula * pajak;
    } else if (beratGula < 25) {
        diskon = 0.3;
        pajak = 0.02;
        totalDiskon = hargaPerKg * beratGula * diskon;
        totalPajak = hargaPerKg * beratGula * pajak;
    } else if (beratGula < 50) {
        diskon = 0.4;
        pajak = 0.03;
        totalDiskon = hargaPerKg * beratGula * diskon;
        totalPajak = hargaPerKg * beratGula * pajak;
    } else if (beratGula >= 50) {
        diskon = 0.5;
        pajak = 0.04;
        totalDiskon = hargaPerKg * beratGula * diskon;
        totalPajak = hargaPerKg * beratGula * pajak;
    }

    double hargaseluruh = hargaPerKg * beratGula;
    double hargaSetelahDiskon = hargaPerKg * beratGula * (1 - diskon);
    double hargaTotal = hargaSetelahDiskon + totalPajak;

    printf("\nHarga total sebelum diskon dan pajak: Rp %.2f\n", hargaseluruh);
    printf("Total diskon: Rp %.2f\n", totalDiskon);
    printf("Total pajak: Rp %.2f\n", totalPajak);
    printf("Harga total (%.2f kg): Rp %.2f\n", beratGula, hargaTotal);

    printf("Jam Pembelian: %s\n", jam);

    printf("Tanggal Pembelian: %s\n", tanggal);


    getch();

    return 0;
}


