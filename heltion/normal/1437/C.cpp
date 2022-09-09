#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200 + 1;
int a[maxn], dp[maxn][maxn << 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, ans = 1E9;
        cin >> n;
        for(int i = 1; i <= n; i += 1) cin >> a[i];
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; i += 1)
            for(int j = 0; j <= 2 * n; j += 1){
                dp[i][j] = 1E9;
                for(int k = 0; k < j; k += 1)
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + abs(j - a[i]));
                if(i == n) ans = min(ans, dp[i][j]);
            }
        cout << ans << "\n";
    }
    return 0;
}