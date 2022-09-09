#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 3000 + 2;
int dp[maxn][maxn], pre[maxn][maxn], add[maxn], a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i += 1) cin >> a[i];
        for(int i = 1; i <= n + 1; i += 1){
            for(int j = 1; j <= n + 1; j += 1){
                dp[i][j] = maxn;
                pre[i][j] = maxn;
            }
            add[i] = 0;
        }
        dp[n][n + 1] = pre[n][n + 1] = 0;
        for(int i = n - 1; i >= 1; i -= 1){
            for(int j = i + 1; j <= n; j += 1)
                if(i + a[i] >= j)
                    dp[i][j] = min(dp[i][j], pre[j][i + a[i] + 1] + add[j]);
                for(int j = n; j > i; j -= 1) pre[i][j] = min(pre[i][j + 1], dp[i][j]);
            for(int j = i + 1; j <= i + a[i]; j += 1) add[j] += 1;
        }
        cout << pre[1][2] << "\n";
    }
    return 0;
}