#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define MN 200000
#define mod 998244353

inline int read() {
    int x; scanf("%d", &x);
    return x;
}
int n, a[MN + 5];

int inv(int x) {
    int res = 1;
    for (int k = mod - 2; k; k >>= 1, x = 1LL * x * x % mod) {
        if (k & 1) {
            res = 1LL * res * x % mod;
        }
    }
    return res;
}

int main() {
    for (int T = read(); T; --T) {
        n = read();
        int num0 = 0, num1 = 0, num = 0;
        for (int i = 1; i <= n; ++i) {
            a[i] = read();
            if (a[i] == 0) {
                ++num0;
                if (a[num0] == 1) ++num;
            } else {
                ++num1;
            }
        }
        int ans = 0;
        int all = 1LL * n * (n - 1) / 2 % mod;
        for (int j = 1; j <= num; ++j) {
            int invj = inv(j);
            ans = (ans + 1LL * invj * invj % mod * all) % mod;
        }
        printf("%d\n", ans);
    }
}