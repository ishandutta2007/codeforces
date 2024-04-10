#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
#include <stack>
#include <queue>
using namespace std;
const int N = 1e3 + 10;
const int mod = 998244353;
int f[N][N], g[N][N];
int mn[N][N], ind[N];
bool bz[N][N];
int a[N];
int n, m;
/*int dfs(int l ,int r) {
    if (l > r) return 1;
    if (bz[l][r]) return f[l][r];
    int x = mn[l][r], id = ind[x];
    bz[l][r] = 1;
    for (int ll = l;ll<= id; ll ++)
        for (int rr = id ; rr <= r; rr ++) {
            f[l][r] += (long long)dfs(ll, id - 1) * dfs(l, ll - 1) % mod * dfs(id + 1, rr) % mod * dfs(rr + 1, r) % mod;
            f[l][r] %= mod;
        }
    return f[l][r];
}*/
int main()
{
   // freopen("input", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m ; i ++)
        scanf("%d", &a[i]), ind[a[i]] = i;
    for (int i =1;  i<= m;  i++) {
        mn[i][i] = a[i];
        for (int j = i+1; j <= m ; j ++)
            mn[i][j] = min(mn[i][j - 1], a[j]);
    }
    for (int i = 1; i <= m + 1 ; i ++)
        f[i][i - 1] = g[i][i - 1] = 1;
    for (int i = 1; i <= m; i ++)
        for (int l = 1; l + i - 1 <= m ; l ++)
        {
            int r = i + l - 1;
            int x = mn[l][r], id = ind[x];
            for (int mid = id; mid <= r; mid ++)
                g[l][r] = (g[l][r] + (long long)f[l][id - 1] * f[mid + 1][r] % mod * f[id + 1][mid] % mod) % mod;

            for (int ll = l;ll<= id; ll ++)
                    f[l][r] = (f[l][r] + (long long)g[ll][r] * f[l][ll - 1])% mod;
         }
    printf("%d\n",f[1][n]);
    return 0;
}