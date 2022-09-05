#include <bits/stdc++.h>
using namespace std;

int n, sz, a[110][110], ans[10010][110];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0, c; j < n; j++) {
            scanf("%d", &c), a[i][c - 1]++;
        }
    }
    while (1) {
        int p = 0;
        while (p < n) {
            int q = 0;
            while (q < n && a[p][q] <= 1) q++;
            if (q < n) break;
            p++;
        }
        if (p == n) break;
        for (int i = 0; i < n; i++) {
            int q = 0;
            while (a[p][q] <= 1) q++;
            ans[sz][p] = q;
            a[p][q]--, a[++p %= n][q]++;
        }
        sz++;
    }
    for (int len = 1; len < n; len++) {
        for (int k = len; k; k--) {
            for (int i = 0; i < n; i++) ans[sz][i] = (i + k) % n;
            sz++;
        }
    }
    printf("%d\n", sz);
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < n; j++) printf("%d ", ans[i][j] + 1);
        putchar('\n');
    }
    return 0;
}