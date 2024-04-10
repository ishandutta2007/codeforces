#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200 + 1;
LL dp[maxn][maxn][maxn];
int n[3], a[3][maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(int i = 0; i < 3; i += 1) cin >> n[i];
    for(int i = 0; i < 3; i += 1){
        for(int j = 1; j <= n[i]; j += 1) cin >> a[i][j];
        sort(a[i] + 1, a[i] + n[i] + 1, greater<int>());
    }
    LL ans = 0;
    int i[3];
#define FOR(x) for(i[x] = 0; i[x] <= n[x]; i[x] += 1)
    FOR(0) FOR(1) FOR(2){
        if(i[0] and i[1])
            ans = max(ans, dp[i[0]][i[1]][i[2]] = max(dp[i[0]][i[1]][i[2]], dp[i[0] - 1][i[1] - 1][i[2]] + a[0][i[0]] * a[1][i[1]]));
        if(i[1] and i[2])
            ans = max(ans, dp[i[0]][i[1]][i[2]] = max(dp[i[0]][i[1]][i[2]], dp[i[0]][i[1] - 1][i[2] - 1] + a[1][i[1]] * a[2][i[2]]));
        if(i[0] and i[2])
            ans = max(ans, dp[i[0]][i[1]][i[2]] = max(dp[i[0]][i[1]][i[2]], dp[i[0] - 1][i[1]][i[2] - 1] + a[0][i[0]] * a[2][i[2]]));
        //cout << i[0] << " " << i[1] << " " << i[2] << " " << dp[i[0]][i[1]][i[2]] << "\n";
    }
    cout << ans;
    return 0;
}