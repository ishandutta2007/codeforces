#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int n, X, Y, f[1 << 22], g[1 << 22];

void chk(int &x, int y) {
    if (x < y) x = y;
}

int main() {
    scanf("%d %d %d", &n, &X, &Y);
    for (int i = 0; i < X + Y; i++) {
        memset(g, 0, sizeof(g));
        int cnt = n / (X + Y) + (i < n % (X + Y));
        for (int j = 0; j < 1 << 22; j++) {
            chk(g[(j << 1) & ((1 << 22) - 1)], f[j]);
            if (j >> (X - 1) & 1 || j >> (Y - 1) & 1) continue;
            chk(g[1 | ((j << 1) & ((1 << 22) - 1))], f[j] + cnt);
        }
        swap(f, g);
    }
    printf("%d\n", *max_element(f, f + (1 << 22)));
    return 0;
}