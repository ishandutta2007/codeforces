#include <bits/stdc++.h>

using namespace std;

int n, k, x, y, f[1025], g[1025];

int main() {
    scanf("%d %d %d", &n, &k, &x);
    for(int i = 0; i < n; i++) {
        scanf("%d", &y);
        f[y]++;
    }
    for(int i = 0; i < k; i++) {
        int parity = 0;
        for(int j = 0; j < 1024; j++) {
            g[j^x] += (f[j] - parity + 1) / 2;
            g[j] += (f[j] + parity) / 2;
            parity ^= (f[j] & 1);
        }
        for(int j = 0; j < 1024; j++) {
            f[j] = g[j];
            g[j] = 0;
        }
    }
    int mini = 1900, maxi = -1;
    for(int i = 0; i < 1024; i++) {
        if(f[i]) mini = min(mini, i);
        if(f[i]) maxi = max(maxi, i);
    }
    printf("%d %d\n", maxi, mini);
    return 0;
}