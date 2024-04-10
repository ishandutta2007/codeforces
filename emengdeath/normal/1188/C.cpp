#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
using namespace std;
const int N = 1e3 + 1;
const int S = 1e5;
const int mod = 998244353;
int n, k;
int a[N], f[N][N], g[N], ans[S + 1];
int ans1;
int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n ; i ++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int diff = S / (k - 1) + 1; diff >= 0 ; diff --) {
        memset(g, 0, sizeof(g));
        g[0] = 1;
        int l = 1;
        for (int i = 1; i <= n; i ++) {
            while (l <= n && a[l] + diff <= a[i]) {
                for (int j = 0; j < k ; j ++)
                    (g[j] += f[l][j]) %= mod;
                l ++;
            }
            for (int j = 0; j < k ; j ++)
                f[i][j + 1] = g[j];
            (ans[diff] += f[i][k]) %= mod;
        }
        if (diff == S / (k - 1) + 1) (ans1 += (long long)ans[diff] * diff % mod) %= mod;
        else
            (ans1 += (long long)(ans[diff] - ans[diff + 1] + mod) % mod * diff % mod ) %= mod;
    }
    printf("%d\n", ans1);
    return 0;
}