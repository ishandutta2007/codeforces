#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 3000;
vector<LL> v[maxn + 1];
LL sum[maxn];
LL ans = 0;
vector<LL> dp;
int n, k;
void add(int x){
    for(int i = k; i >= v[x].size(); i -= 1) dp[i] = max(dp[i], dp[i - v[x].size()] + v[x].back());
}
void DFS(int L, int R){
    if(L == R){
        ans = max(ans, dp[k]);
        for(int j = 0; j < v[L].size() and j < k; j += 1) ans = max(ans, v[L][j] + dp[k - j - 1]);
        return;
    }
    int M = (L + R) >> 1;
    auto tmp = dp;
    for(int i = M + 1; i <= R; i += 1) add(i);
    DFS(L, M);
    swap(dp, tmp);
    for(int i = L; i <= M; i += 1) add(i);
    DFS(M + 1, R);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for(int i = 1; i <= n; i += 1){
        int t;
        cin >> t;
        v[i].resize(t);
        for(LL& x : v[i]) cin >> x;
        partial_sum(v[i].begin(), v[i].end(), v[i].begin());
    }
    dp.resize(k + 1);
    DFS(1, n);
    cout << ans;
    return 0;
}