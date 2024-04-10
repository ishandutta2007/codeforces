#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000 + 1;
constexpr int maxd = 2000000;
constexpr int maxw = 20;
constexpr LL inf = 1'000'000'000;
constexpr LL mod = 998'244'353;
vector<int> G[maxn], H[maxn];
int d[maxn * maxw];
vector<int> q[maxd];
pair<LL, LL> dp[maxn * 2];
vector<int> qp[maxn];
bool cmp(pair<LL, LL> p1, pair<LL, LL> p2){
    if(p1.first == p2.first) return p1.second < p2.second;
    if(p1.first > p2.first) return not cmp(p2, p1);
    while(p1.first < p2.first){
        if(p1.first > maxw) return 1;
        p2.second += 1LL << (maxw - 2 + p2.first);
        p2.first -= 1;
    }
    return p1.second < p2.second;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 1, u, v; i <= m; i += 1){
        cin >> u >> v;
        G[u].push_back(v);
        H[v].push_back(u);
    }
    for(int i = 0; i < n * maxw; i += 1) d[i] = inf;
    q[d[0] = 0].push_back(0);
    for(int i = 0; i < maxd; i += 1)
        for(int j : q[i])
            if(d[j] == i){
                int u = j / maxw + 1, v = j % maxw;
                //cout << u << " " << v << " " << d[j] << "\n";
                if(v + 1 < maxw){
                    int nd = (1 << v) + d[j], k = (u - 1) * maxw + v + 1;
                    if(nd < maxd and nd < d[k]) q[d[k] = nd].push_back(k);
                }
                for(int x : ((v & 1) ? H[u] : G[u])){
                    int nd = 1 + d[j], k = (x - 1) * maxw + v;
                    if(nd < maxd and nd < d[k]) q[d[k] = nd].push_back(k);
                }
            }
    int ans = inf;
    for(int i = 0; i < maxw; i += 1) ans = min(ans, d[(n - 1) * maxw + i]);
    //cout << ans;
    for(int i = 0; i < n * 2; i += 1) dp[i] = {inf, inf};
    dp[(n - 1) * 2] = {0, 0};
    dp[(n - 1) * 2 + 1] = {0, 0};
    qp[0].push_back((n - 1) * 2);
    qp[0].push_back((n - 1) * 2 + 1);
    for(int i = 0; i < maxn; i += 1)
        for(int x = 0; x < qp[i].size(); x += 1){
            int j = qp[i][x];
            int u = j / 2 + 1, v = j % 2;
            //cout << u << " " << v << " " << dp[j].first << " " << dp[j].second << "\n";
            {
                auto nd = make_pair(dp[j].first + 1, dp[j].second);
                int k = (u - 1) * 2 + (v ^ 1);
                if(nd < dp[k]){
                    dp[k] = nd;
                    qp[nd.first].push_back(k);
                }
            }
            for(int x : ((v & 1) ? G[u] : H[u])){
                auto nd = make_pair(dp[j].first, dp[j].second + 1);
                int k = (x - 1) * 2 + v;
                if(nd < dp[k]){
                    dp[k] = nd;
                    qp[nd.first].push_back(k);
                }
            }
        }
    //cout << dp[1].first << " " << dp[1].second << "\n";
    auto pans = make_pair(inf, inf);
    if(ans < inf) pans = {0, ans};
    for(int i = 1; i <= n; i += 1) if(d[i * maxw - 1] < inf){
        auto tmp = make_pair(dp[i * 2 - 1].first, d[i * maxw - 1] + dp[i * 2 - 1].second);
        //cout << pans.first << " " << pans.second << "\n";
        //cout << tmp.first << " " << tmp.second << "\n";
        //cout << cmp(tmp, pans) << "\n";
        if(cmp(tmp, pans)) pans = tmp;
    }
    LL f = 0;
    if(pans.first){
        f = 1;
        for(int i = 1; i <= pans.first; i += 1) f = f * 2 % mod;
        f = (f - 1) % mod;
        for(int i = 1; i <= 19; i += 1) f = f * 2 % mod;
    }
    cout << (f + pans.second) % mod;
    return 0;
}