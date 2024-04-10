#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

template<typename T>
vector<T> dijkstra(vector<vector<pair<T, int>>>& adj, int s) {

    const static T inf_T = numeric_limits<T>::max();
    int n = adj.size();
    vector<bool> vis(n, 0);
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> heap;
    heap.push({0, s});
    vector<T> out(n, inf_T);

    while (!heap.empty()) {
        auto [c, i] = heap.top(); heap.pop();
        if (vis[i]) continue;
        vis[i] = 1;
        out[i] = c;
        for (auto& [w, j] : adj[i])
            if (!vis[j])
                heap.push({c+w, j});
    }
    return out;
}

vector<int> topologicalsort(vector<vector<int>>& adj) {

    int size = adj.size();
    vector<int> out, stk, in(size, 0);
    vector<bool> visited(size, 0);

    for (int i = 0; i < size; i++)
        for (int j : adj[i])
            in[j]++;
    for (int i = 0; i < size; i++)
        if (in[i] == 0)
            stk.push_back(i);

    while (!stk.empty()) {
        int i = stk.back();
        stk.pop_back();
        out.push_back(i);
        for (int j : adj[i]) {
            in[j]--;
            if (in[j] == 0)
                stk.push_back(j);
        }
    }
    return out;
}

const int N = 1e6+5;
const ll mod = 1e9+7;
ll r[N], len[N];
bool vis[N];
pair<int, int> e[N];
vector<vector<pair<int, int>>> adj, dag;
map<int, int> s;

void dfs(vector<int> u, ll x) {
    for (auto& i : u) {
        vis[i] = 1;
        if (i < N) r[i] = x;
    }
    s.clear();
    for (auto& i : u)
        for (auto& [w, j] : dag[i])
            if (!vis[j]) {
                if (!s.count(j)) s[j] = w;
                else s[j] = min(s[j], w);
            }
    vector<int> v[10];
    for (auto& [j, w] : s)
        v[w].pb(j);
    for (int i = 0; i < 10; i++)
        if (v[i].size() > 0)
            dfs(v[i], (x*10+i)%mod);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < N; i++)
        len[i] = to_string(i).size();
    adj.resize(n), dag.resize(n);
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        e[i] = {--u, --v};
        adj[u].pb({len[i], v}), adj[v].pb({len[i], u});
    }
    auto c = dijkstra(adj, 0);
    int k = n;
    for (int i = 1, j; i <= m; i++) {
        auto& [u, v] = e[i];
        if (c[u] > c[v]) swap(u, v);
        if (c[v] != c[u]+len[i]) continue;
        for (j = i; j >= 10; j /= 10)
            dag.pb({{j%10, v}}), v = k++;
        dag[u].pb({j, v});
    }
    dfs({0}, 0);
    for (int i = 1; i < n; i++)
        cout << r[i] << "\n";
}