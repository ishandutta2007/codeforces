#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2007;

struct Edge {
    int u, v, c;    
}; 

int n, m;
int a[MAXN];
vector <Edge> ed;

void read() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        --u; --v;
        ed.push_back({u, v, c});
    }   
}

const int INF = 1e16 + 7;

struct EDGE {
    int u, v, f, c;
};

vector <EDGE> d;
vector <int> g[MAXN];

void add(int u, int v, int c) {
    //cout << "edge " << u << ' ' << v << ' ' << c << '\n';
    g[u].push_back(d.size());
    d.push_back({u, v, 0, c});
    g[v].push_back(d.size());
    d.push_back({v, u, 0, 0});
}   

int S, T;

void build() {
    S = 0;
    T = n + m + 1;
    for (int i = 0; i < m; ++i) {
        add(S, i + 1, ed[i].c);
    }
    for (int i = 0; i < n; ++i) {
        add(m + i + 1, T, a[i]); 
    }
    for (int i = 0; i < m; ++i) {
        add(i + 1, ed[i].u + m + 1, INF);
        add(i + 1, ed[i].v + m + 1, INF);
    }   
}

int dist[MAXN];
bool bfs() {
    for (int i = 0; i < MAXN; ++i) dist[i] = INF;
    queue <int> q;
    q.push(S);
    dist[S] = 0;
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int num : g[u]) {
            auto e = d[num];
            if (e.f == e.c) {
                continue;
            }   
            if (dist[u] + 1 < dist[e.v]) {
                dist[e.v] = dist[u] + 1;
                q.push(e.v);
            }   
        }   
    }   
    return dist[T] != INF;
}   

int ptr[MAXN];
int dfs(int u, int curr) {
    if (u == T) return curr;
    for (; ptr[u] < g[u].size(); ++ptr[u]) {
        int num = g[u][ptr[u]];
        auto e = d[num];
        if (dist[u] + 1 != dist[e.v]) {
            continue;
        }   
        if (e.f == e.c) {
            continue;
        }   
        int t = dfs(e.v, min(curr, e.c - e.f));
        if (t) {
            d[num].f += t;
            d[num ^ 1].f -= t;
            return t;
        }   
    }   
    return 0;
}   

int dinic() {
    int ans = 0;
    while (1) {
        if (!bfs()) {
            break;
        }   
        for (int i = 0; i < MAXN; ++i) ptr[i] = 0;
        while (1) {
            int add = dfs(S, INF);
            if (!add) {
                break;
            }   
            else {
                ans += add;
            }
        }   
    }   
    return ans;
}   

int sh;
void solve() {
    build();
    sh = dinic();
}

void print() {
    int best = 0;
    for (auto e : ed) {
        best += e.c;
    }
    cout << best - sh << '\n';
}   

signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #endif

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    read();
    solve();
    print();

    return 0;
}