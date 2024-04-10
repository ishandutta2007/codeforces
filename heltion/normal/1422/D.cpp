#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000;
constexpr LL inf = 2'000'000'000;
int x[maxn], y[maxn];
int dx[maxn], dy[maxn], done[maxn << 1];
LL d[maxn << 1];
vector<int> G[maxn << 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, sx, sy, fx, fy;
    cin >> n >> m;
    cin >> sx >> sy >> fx >> fy;
    for(int i = 0; i < m; i += 1){
        cin >> x[i] >> y[i];
        dx[i] = x[i];
        dy[i] = y[i];
    }
    sort(dx, dx + m);
    sort(dy, dy + m);
    int mx = unique(dx, dx + m) - dx;
    int my = unique(dy, dy + m) - dy;
    for(int i = 0; i < mx + my; i += 1) d[i] = inf;
    for(int i = 0; i < m; i += 1){
        int u = lower_bound(dx, dx + mx, x[i]) - dx;
        int v = lower_bound(dy, dy + my, y[i]) - dy;
        G[u].push_back(v + mx);
        G[v + mx].push_back(u);
        d[u] = min(d[u], (LL)abs(sx - x[i]));
        d[v + mx] = min(d[v + mx], (LL)abs(sy - y[i]));
    }
    priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> q;
    for(int i = 0; i < mx + my; i += 1) q.push({d[i], i});
    while(not q.empty()){
        auto [_, u] = q.top();
        q.pop();
        if(done[u]) continue;
        done[u] = 1;
        for(int v : G[u])
            if(d[v] > d[u])
                q.push({d[v] = d[u], v});
        if(u + 1 < mx and d[u + 1] > d[u] + dx[u + 1] - dx[u]) q.push({d[u + 1] = d[u] + dx[u + 1] - dx[u], u + 1});
        if(u < mx and u > 0 and d[u - 1] > d[u] + dx[u] - dx[u - 1]) q.push({d[u - 1] = d[u] + dx[u] - dx[u - 1], u - 1});
        if(u + 1 < mx + my and u >= mx and d[u + 1] > d[u] + dy[u - mx + 1] - dy[u - mx]) q.push({d[u + 1] = d[u] + dy[u - mx + 1] - dy[u - mx], u + 1});
        if(u > mx and d[u - 1] > d[u] + dy[u - mx] - dy[u - mx - 1]) q.push({d[u - 1] = d[u] + dy[u - mx] - dy[u - mx - 1], u - 1});
    }
    int ans = abs(sx - fx) + abs(sy - fy);
    for(int i = 0; i < m; i += 1){
        int u = lower_bound(dx, dx + mx, x[i]) - dx;
        ans = min((LL)ans, d[u] + abs(x[i] - fx) + abs(y[i] - fy));
    }
    cout << ans;
    return 0;
}