#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100;
LL dp[maxn][maxn];
LL h[maxn][maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, m;
        cin >> n >> m;
        set<LL> s;
        for(int i = 0; i < n; i += 1)
            for(int j = 0; j < m; j += 1){
                cin >> h[i][j];
                h[i][j] -= i + j;
                s.insert(h[i][j]);
            }
        LL ans = LLONG_MAX;
        for(LL x : s){
            for(int i = 0; i < n; i += 1)
                for(int j = 0; j < m; j += 1){
                    dp[i][j] = -1;
                    if(x > h[i][j]) continue;
                    if(i == 0 and j == 0) dp[i][j] = 0;
                    else{
                        if(i) dp[i][j] = dp[i - 1][j];
                        if(j and ~dp[i][j - 1])
                            if(dp[i][j] == -1 or dp[i][j] > dp[i][j - 1]) dp[i][j] = dp[i][j - 1];
                    }
                    if(dp[i][j] != -1) dp[i][j] += h[i][j] - x;
                }
            if(~dp[n - 1][m - 1])
                ans = min(ans, dp[n - 1][m - 1]);
        }
        cout << ans << "\n";
    }
    return 0;
}