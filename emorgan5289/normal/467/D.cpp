#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

void visit(ll i, vector<vector<ll>>& adj, vector<ll>& order, vector<bool>& visited) {
    visited[i] = 1;
    for (ll j : adj[i])
        if (!visited[j])
            visit(j, adj, order, visited);
    order.push_back(i);
}

void partition(ll i, ll c, vector<ll>& component, vector<vector<ll>>& adj, vector<bool>& visited) {
    visited[i] = 1;
    component[i] = c;
    for (ll j : adj[i])
        if (!visited[j])
            partition(j, c, component, adj, visited);
}

// accepts an adjacency list, unweighted.
vector<ll> kosaraju(vector<vector<ll>>& adj) {

    ll size = adj.size();
    vector<ll> order, out(size);
    vector<vector<ll>> rev_adj(size);
    vector<bool> visited(size, 0);

    for (ll i = 0; i < size; i++)
        if (!visited[i])
            visit(i, adj, order, visited);

    for (ll i = 0; i < size; i++)
        visited[i] = 0;
    for (ll i = 0; i < size; i++)
        for (ll j : adj[i])
            rev_adj[j].push_back(i);

    ll c = -1;
    for (ll i = size-1; i >= 0; i--)
        if (!visited[order[i]])
            partition(order[i], ++c, out, rev_adj, visited);

    return out;
}

// Accepts an adjacency list, as well as the component vector produced by kosaraju.
// Returns an adjacency list, which is the component-wise DAG of the graph.
// Runs in O(E).
vector<vector<ll>> kosaraju_dag(vector<vector<ll>>& adj, vector<ll>& components) {

    ll count = 0;
    for (auto& x : components) count = max(count, x+1);

    vector<unordered_set<ll>> dag(count);
    for (ll i = 0; i < adj.size(); i++)
        for (ll j : adj[i])
            if (components[i] != components[j])
                dag[components[i]].insert(components[j]);

    vector<vector<ll>> out(count);
    for (ll i = 0; i < count; i++)
        for (ll j : dag[i])
            out[i].push_back(j);
    return out;
}

vector<ll> topologicalsort(vector<vector<ll>>& adj) {

    ll size = adj.size();
    vector<ll> out, stk, in(size, 0);
    vector<bool> visited(size, 0);

    for (ll i = 0; i < size; i++)
        for (ll j : adj[i])
            in[j]++;
    for (ll i = 0; i < size; i++)
        if (in[i] == 0)
            stk.push_back(i);

    while (!stk.empty()) {
        ll i = stk.back();
        stk.pop_back();
        out.push_back(i);
        for (ll j : adj[i]) {
            in[j]--;
            if (in[j] == 0)
                stk.push_back(j);
        }
    }
    return out;
}

const ll maxn = 400005;
ll a[maxn];
pair<ll, ll> c[maxn], dp[maxn];
vector<vector<ll>> adj;
ll t = 0;
unordered_map<string, ll> h;

ll ins(string& s) {
    transform(all(s), s.begin(), ::tolower);
    if (h.count(s))
        return h[s];
    c[t] = {count(all(s), 'r'), s.size()};
    h[s] = t++;
    return t-1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll m; cin >> m;
    for (ll i = 0; i < m; i++) {
        string s; cin >> s; a[i] = ins(s);
        while (adj.size() <= a[i]) adj.pb({});
    }
    fill(dp, dp+maxn, make_pair(inf, inf));
    ll n; cin >> n;
    for (ll i = 0; i < n; i++) {
        string s1, s2; cin >> s1 >> s2;
        ll k = max(ins(s1), ins(s2));
        while (adj.size() <= k) adj.pb({});
        adj[ins(s1)].pb(ins(s2));
    }
    auto comp = kosaraju(adj);
    auto dag = kosaraju_dag(adj, comp);
    auto topo = topologicalsort(dag);
    for (ll i = 0; i < adj.size(); i++)
        dp[comp[i]] = min(dp[comp[i]], c[i]);
    reverse(all(topo));
    debug(adj);
    debug(dag);
    debug(topo);
    for (auto& i : topo)
        for (auto& j : dag[i]) {
            debug(i, j);
            dp[i] = min(dp[i], dp[j]);
        }
    for (ll i = 0; i < adj.size(); i++)
        debug(i, dp[comp[i]]);
    pair<ll, ll> out = {0, 0};
    for (ll i = 0; i < m; i++) {
        out.first += dp[comp[a[i]]].first;
        out.second += dp[comp[a[i]]].second;
    }
    cout << out.first << " " << out.second << "\n";
}