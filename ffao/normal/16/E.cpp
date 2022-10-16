#include <stdio.h>

double pd[1<<18];
int n;
double a[18][18];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
    
    pd[(1<<n)-1] = 1;
    for (int bm = (1<<n)-1; bm >= 1; bm--) {
        double cont = __builtin_popcount(bm);
        cont = cont*(cont-1)/2;
        for (int j = 0; j < n; j++) {
            if (!(bm & (1<<j))) continue;
            for (int k = j+1; k < n; k++) {
                if (!(bm & (1<<k))) continue;
                pd[bm ^ (1<<j)] += pd[bm] * a[k][j] / cont;
                pd[bm ^ (1<<k)] += pd[bm] * a[j][k] / cont;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        printf("%.15lf ", pd[1<<i]);
    }
    printf("\n");
}