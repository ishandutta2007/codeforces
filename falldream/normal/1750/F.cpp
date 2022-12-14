#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define MN 5000
using namespace std;
int n, mod, f[MN + 5], g[MN + 5], ans[MN + 5], pw[MN + 5];
/*
f : has encountered the first 1 subsequence, still want a 1 subsequence
g : want no more 1 subsequence
*/
int main() {
    scanf("%d%d", &n, &mod);
    pw[0] = g[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pw[i] = 2LL * pw[i - 1] % mod;
        g[i] = g[i - 1];
        f[i] = f[i - 1];
        for (int j = 1; j < i; ++j) {
            if (3 * j + 1 < i) {
                f[i] = (f[i] + 1LL * f[i - 3 * j - 1] * ans[j]) % mod;   // 0...01...10...0
            }
            if (2 * j < i) {
                g[i] = (g[i] + 1LL * f[i - 2 * j] * ans[j]) % mod;   // 0...01...1
            }
            if (2 * j < i) {
                f[i] = (f[i] + ans[j]) % mod;   // 1...10...0
            }
            g[i] = (g[i] + ans[j]) % mod; // ...01...1
        }
        if (i > 1) {
            g[i] = (g[i] + ans[i - 1]) % mod;  // 1...10
        }
        ans[i] = (pw[i] + mod - g[i]) % mod;
        // printf("f[%d]=%d, g[%d]=%d, h[%d]=%d ans[%d]=%d\n", i, f[i], i, g[i], i, h[i], i, ans[i]);
    }
    cout << ans[n];
    return 0;
}