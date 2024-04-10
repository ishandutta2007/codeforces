#include <stdio.h>

const int lim = 10000000;
int p[lim];
int cont[lim];
int n, k, inp;

int main() {
    for (int i = 2; i*i < lim; i++) {
        if (!p[i]) {
            for (int x = i*i; x < lim; x+=i) {
                p[x] = 1;
            }
        }
    } 

    scanf("%d %d", &n, &k);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp);
        if (inp < lim) cont[inp]++;
    }
    
    if (k == 2) {
        printf("0\n");
        return 0;
    }
    
    if (cont[1]) {
        printf("1\n");
        return 0;
    }
    
    if (k >= lim-10) {
        printf("-1\n");
        return 0;
    }
    
    int ans = 0;
    bool ok = true;
    for (int i = 2; i < k; i++) {
        if (!p[i]) {
            if (cont[i]) ans++;
            else ok = false;
        }
    }
    
    if (ok) printf("%d\n", ans);
    else printf("-1\n");
}