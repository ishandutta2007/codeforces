#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 2200;
LL a[maxn * 2], b[maxn * 2];
using PII = pair<int, int>;
constexpr int inf = 1000000000;
struct SSPA{
    struct Edge{
        int u, v, f, c;
    };
    int n, s, t;
    vector<Edge> edges;
    vector<vector<int>> adj;
    vector<int> h, d, p, done;
    SSPA(int n, int s, int t) : n(n), s(s), t(t){
        adj.resize(n);
        h.resize(n);
        d.resize(n);
        p.resize(n);
        done.resize(n);
    }
    void add(int u, int v, int f, int c){
        adj[u].push_back(edges.size());
        edges.push_back({u, v, f, c});
        adj[v].push_back(edges.size());
        edges.push_back({v, u, 0, -c});
    }
    bool BFS01(){
        fill(d.begin(), d.end(), inf);
        fill(p.begin(), p.end(), -1);
        fill(done.begin(), done.end(), 0);
        deque<int> q;
        d[s] = 0;
        q.push_front(s);
        while(not q.empty()){
            int u = q.front();
            q.pop_front();
            if(done[u]) continue;
            done[u] = 1;
            for(int i : adj[u]){
                if(auto& e = edges[i]; e.f and d[e.v] > d[u] + e.c + h[u] - h[e.v]){
                    p[e.v] = i;
                    d[e.v] = d[u] + e.c + h[u] - h[e.v];
                    if(d[e.v] == d[u]) q.push_front(e.v);
                    else q.push_back(e.v);
                }
            }
        }
        return ~p[t];
    }
    int min_cost_flow(){
        int flow = 0, cost = 0;
        while(BFS01()){
            for(int i = 0; i < n; i += 1) h[i] += d[i];
            int f = inf;
            for(int u = t; u != s; u = edges[p[u]].u) f = min(f, edges[p[u]].f);
            flow += f;
            cost += f * h[t];
            for(int u = t; u != s; u = edges[p[u]].u){
                edges[p[u]].f -= f;
                edges[p[u] ^ 1].f += f;
            }
        }
        return cost;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < 2 * n; i += 1) cin >> a[i] >> b[i];
    LL L = 0, R = 1000000000 + 1;
    vector<int> u;
    for(int i = 0; i < 2 * n; i += 1) u.push_back(i);
    sort(u.begin(), u.end(), [&](const int& x, const int& y){
        if(b[x] != b[y]) return b[x] < b[y];
        return a[x] > a[y];
    });
    while(L < R){
        LL M = (L + R) >> 1;
        vector<LL> v, w;
        LL m = 0;
        for(int i : u){
            m = max(m, a[i] * M + b[i]);
            if(i < n) v.push_back(m);
            else w.push_back(a[i] * M + b[i]);
        }
        int ok = 1;
        sort(w.begin(), w.end());
        for(int i = 0; i < n; i += 1)
            ok &= v[i] >= w[i];
        if(ok) R = M;
        else L = M + 1;
    }
    if(L == 1000000000 + 1){
        cout << "-1";
        return 0;
    }
    cout << L << " ";
    int s = 0, t = 8 * n + 1;
    SSPA SSPA(t + 1, s, t);
    for(int i = 0; i < n; i += 1) SSPA.add(s, i + 1, 1, 0);
    for(int i = n; i < 2 * n; i += 1) SSPA.add(4 * n + i + 1, t, 1, 0);
    for(int i = 0; i < 2 * n; i += 1){
        SSPA.add(2 * n + i + 1, i + 1, inf, 0);
        SSPA.add(i + 1, 2 * n + i + 1, inf, 1);
        SSPA.add(6 * n + i + 1, 4 * n + i + 1, inf, 0);
        SSPA.add(4 * n + i + 1, 6 * n + i + 1, inf, 1);
        SSPA.add(i + 1, 4 * n + i + 1, inf, 0);
    }
    for(int i = 1; i < 2 * n; i += 1){
        SSPA.add(2 * n + u[i] + 1, 2 * n + u[i - 1] + 1, inf, 0);
        if(b[u[i]] == b[u[i - 1]])
            SSPA.add(2 * n + u[i - 1] + 1, 2 * n + u[i] + 1, inf, 0);
    }
    sort(u.begin(), u.end(), [&](const int& x, const int& y){
        return a[x] * L + b[x] < a[y] * L + b[y];
    });
    for(int i = 1; i < 2 * n; i += 1){
        SSPA.add(6 * n + u[i] + 1, 6 * n + u[i - 1] + 1, inf, 0);
        if(a[u[i]] * L + b[u[i]] == a[u[i - 1]] * L + b[u[i - 1]])
            SSPA.add(6 * n + u[i - 1] + 1, 6 * n + u[i] + 1, inf, 0);
    }
    cout << SSPA.min_cost_flow();
    return 0;
}