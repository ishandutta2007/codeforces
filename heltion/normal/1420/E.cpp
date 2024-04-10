#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 80;
constexpr int inf = 100000;
int dp[2][maxn + 1][maxn + 1][maxn * (maxn - 1) / 2 + 1]; //0, 1, k
int a[maxn], p[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m = 0;
    cin >> n;
    for(int i = 1; i <= n; i += 1){
        cin >> a[i];
        if(a[i]) p[m += 1] = i;
    }
    int z = n * (n - 1) / 2;
    for(int k = 0; k <= z; k += 1)
        dp[0][0][0][k] = -inf;
    dp[0][0][0][0] = 0;
    for(int x = 1; x <= n; x += 1){
        int v = x & 1, u = v ^ 1;
        for(int i = 0; i <= x and i <= n - m; i += 1)
            for(int j = 0; i + j <= x and j <= m; j += 1)
                for(int k = 0; k <= z; k += 1)
                    dp[v][i][j][k] = -inf;
        for(int i = 0; i <= x - 1 and i <= n - m; i += 1)
            for(int j = 0; i + j <= x - 1 and j <= m; j += 1)
                for(int k = 0; k <= z; k += 1)if(dp[u][i][j][k] != -inf){
                    //cout << x - 1 << " " << i << " " << j << " " << k << " " << dp[u][i][j][k] << endl;
                    if(i < n - m){
                        int ni = i + 1;
                        int nj = j;
                        int nk = k;
                        int nd = x - 1 - i - j;
                        dp[v][ni][nj][nk] = max(dp[u][i][j][k] + nd, dp[v][ni][nj][nk]);
                    }
                    if(j < m){
                        int ni = 0;
                        int nj = j + 1;
                        int nk = k + abs(p[j + 1] - x);
                        if(nk > z) continue;
                        dp[v][ni][nj][nk] = max(dp[u][i][j][k], dp[v][ni][nj][nk]);
                    }
                }
    }
    for(int i = 0, u = n & 1; i <= z; i += 1){
        int ans = 0;
        for(int j = 0; j <= n; j += 1)
            for(int k = 0; k <= i; k += 1) ans = max(dp[u][j][m][k], ans);
        cout << ans << " ";
    }
    return 0;
}