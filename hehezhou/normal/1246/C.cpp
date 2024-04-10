#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, m;
char mp[2010][2010];
int sumline[2010][2010], sumcol[2010][2010];
int dpline[2010][2010], dpcol[2010][2010];
int main() {
    scanf("%d%d", &n, &m);
    if(n == 1 && m == 1) return puts("1"), 0;
    for(int i = 1; i <= n; i++) scanf("%s", mp[i] + 1);
    for(int i = n; i >= 1; i--)
        for(int j = m; j >= 1; j--)
            sumline[i][j] = sumline[i][j + 1] + (mp[i][j] == 'R'),
            sumcol[i][j] = sumcol[i + 1][j] + (mp[i][j] == 'R');
    dpline[1][1] = 1;
    dpcol[1][1] = 1;
    dpline[1][2] = dpcol[2][1] = mod - 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            // cerr << i << ' ' << j << ' ' << dpcol[i][j] << ' ' << dpline[i][j] << endl;
            // cerr << m - sumline[i][j + 1] << ' ' << n - sumcol[i + 1][j] << endl;
            dpline[i][j + 1] = (dpline[i][j + 1] + dpline[i][j]) % mod;
            dpcol[i + 1][j] = (dpcol[i + 1][j] + dpcol[i][j]) % mod;
            dpline[i][j + 1] = (dpline[i][j + 1] + dpcol[i][j]) % mod;
            dpline[i][m + 1 - sumline[i][j + 1]] = (dpline[i][m + 1 - sumline[i][j + 1]] + mod - dpcol[i][j]) % mod;
            dpcol[i + 1][j] = (dpcol[i + 1][j] + dpline[i][j]) % mod;
            dpcol[n + 1 - sumcol[i + 1][j]][j] = (dpcol[n + 1 - sumcol[i + 1][j]][j] + mod - dpline[i][j]) % mod;
        }
    return cout << (dpcol[n][m] + dpline[n][m]) % mod << endl, 0;
}