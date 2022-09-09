#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000;
LL a[maxn + 1], s[maxn + 1][7];
int id[maxn + 1];
LL dp[maxn + 1][1 << 7];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, p, k;
    cin >> n >> p >> k;
    for(int i = 1; i <= n; i += 1){
        cin >> a[i];
        id[i] = i;
    }
    sort(id + 1, id + n + 1, [](const int& x, const int& y){
        return a[x] > a[y];
    });
    for(int i = 1; i <= n; i += 1)
        for(int j = 0; j < p; j += 1)
            cin >> s[i][j];
    LL ans = 0;
    fill(dp[0] + 1, dp[0] + (1 << p), -1e18);
    for(int i = 0; i <= p; i += 1){
        for(int j = 1; j <= k + i; j += 1)
            for(int mask = 0; mask < (1 << p); mask += 1){
                dp[j][mask] = dp[j - 1][mask] + a[id[j]];
                for(int x = 0; x < p; x += 1) if((mask >> x) & 1)
                    dp[j][mask] = max(dp[j][mask], dp[j - 1][mask ^ (1 << x)] + s[id[j]][x]);
                //cout << i << " " << j << " " << mask << " " << dp[j][mask] << endl;
            }
        for(int mask = 0; mask < (1 << p); mask += 1)
            if(__builtin_popcount(mask) < i)
                dp[k + i][mask] = -1e18;
        for(int j = k + i + 1; j <= n; j += 1)
            for(int mask = 0; mask < (1 << p); mask += 1){
                dp[j][mask] = dp[j - 1][mask];
                for(int x = 0; x < p; x += 1) if((mask >> x) & 1)
                    dp[j][mask] = max(dp[j][mask], dp[j - 1][mask ^ (1 << x)] + s[id[j]][x]);
            }
        //cout << i << " " << dp[n][(1 << p) - 1] << endl;
        ans = max(ans, dp[n][(1 << p) - 1]);
    }
    cout << ans;
    return 0;
}