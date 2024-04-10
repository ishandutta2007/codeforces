#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 1e5 + 7;
int n, k;
vector <int> g[N];
int dist[N];

ii dfs(int u, int p) {
    ii ans = mp(0, u);
    for (int v : g[u]) {
        if (v != p) {
            auto t = dfs(v, u);
            ++t.f;
            ans = max(ans, t);
        }   
    }   
    return ans;
}   
vector <int> path, cur;
void find(int u, int p, int w) {
    cur.app(u);
    if (u == w) path = cur;
    for (int v : g[u]) {
        if (v != p) {
            find(v, u, w);
        }   
    }   
    cur.pop_back();
}

int pw[N];

int h[N];
void dfs1(int u, int p) {
    h[u] = 0;
    for (int v : g[u]) {
        if (v != p) {
            dfs1(v, u);
            h[u] = max(h[u], h[v] + 1);
        }   
    }   
    if (h[u] + dist[u] != k) {
        cout << "No\n";
        exit(0);
    }   
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].app(v); g[v].app(u);
    }   

    auto l = dfs(1, 1);
    auto r = dfs(l.s, l.s);
    find(l.s, l.s, r.s);    
    int S = path[path.size() >> 1];

    for (int i = 1; i <= n; ++i)
        dist[i] = N;
    queue <int> q;
    dist[S] = 0;
    q.push(S);
    int diam = 0;
    while (q.size()) {
        int u = q.front(); q.pop();
        diam = dist[u];
        for (int v : g[u]) {
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                q.push(v);
                ++pw[u];
            }   
        }   
    }   
    if (diam != k) {
        cout << "No\n";
        exit(0);
    }   
    dfs1(S, S);
    for (int i = 1; i <= n; ++i) {
        if (pw[i] && pw[i] < 3) {
            cout << "No\n";
            exit(0);
        }
    }   
    cout << "Yes\n";
}