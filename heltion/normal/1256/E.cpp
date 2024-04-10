#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
pair<int, int> p[maxn];
LL dp[maxn];
int pre[maxn], ans[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i += 1){
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p + 1, p + n + 1);
    for(int i = 1; i <= n; i += 1){
        dp[i] = INT_MAX;
        for(int j = max(i - 5, 0); j <= i - 3; j += 1)
            if(dp[j] + p[i].first - p[j + 1].first <= dp[i]){
                dp[i] = dp[j] + p[i].first - p[j + 1].first;
                pre[i] = j;
            }
    }
    int k = 0;
    for(int u = n; u; u = pre[u]){
        k += 1;
        for(int i = u; i > pre[u]; i -= 1) ans[p[i].second] = k;
    }
    cout << dp[n] << " " << k << "\n";
    for(int i = 1; i <= n; i += 1) cout << ans[i] << " ";
    return 0;
}