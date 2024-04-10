#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 5000 + 1;
int a[maxn], dp[maxn][maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i += 1) cin >> a[i];
    for(int i = 0; i <= n; i += 1)
        for(int j = 0; j <= n; j += 1)
            dp[i][j] = maxn;
    dp[0][0] = 0;
    for(int i = 1; i <= n; i += 1){
        int m = maxn;
        for(int j = n; j >= 0; j -= 1){
            m = min(m, dp[i - 1][j]);
            if(j <= a[i]) dp[i][j] = m + (a[i] > j);
        }
        m = maxn;
        for(int j = 0; j <= min(n, a[i]); j += 1){
            m = min(m, dp[i - 1][j] - j);
            dp[i][j] = min(dp[i][j], m + j + (a[i] > j));
        }
        for(int j = 0; j <= n; j += 1){
            //cout << i << " " << j << " " << dp[i][j] << "\n";
        }
    }
    cout << *min_element(dp[n], dp[n] + n + 1);
    return 0;
}