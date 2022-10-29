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
const int N = 2e3 + 10;
const int mod = 998244353;
int f[N][N], g[N][N];
int mn[N][N], indl[N], indr[N];
bool bz[N][N];
int a[1000001];
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
        scanf("%d", &a[i]);
    int x = m ;
    m = 1;
    for (int i = 2; i <= x ; i ++)
        if (a[i] != a[m]) a[++m] = a[i];
    for (int i = 1;i <= m ; i++) {
        if (!indl[a[i]])indl[a[i]] = i;
        indr[a[i]] = i;
    }
    if (m > 3 * n) {
        printf("0\n");
        return 0;
    }
    for (int i = 1; i <= n ; i++)
        for (int j = indl[i]; j <= indr[i]; j ++)
            if (a[j] < i) {
                printf("0\n");
                return 0;
            }
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
            int x = mn[l][r], idl = indl[x], idr = indr[x];
            if (idl > r || idr < l) continue;
            int v = 1;
            int lll = idl;
            while (lll != idr)
            {
                int rrr = lll + 1;
                while (a[rrr] != a[lll]) rrr ++;
                v = (long long)v * f[lll + 1][rrr - 1] % mod;
                lll = rrr;
            }
            for (int mid = idr; mid <= r; mid ++)
                g[l][r] = (g[l][r] + (long long)f[l][idl - 1] * f[mid + 1][r] % mod * v % mod * f[idr + 1][mid] % mod) % mod;

            for (int ll = l;ll<= idl; ll ++)
                    f[l][r] = (f[l][r] + (long long)g[ll][r] * f[l][ll - 1])% mod;
         }
    printf("%d\n",f[1][m]);
    return 0;
}