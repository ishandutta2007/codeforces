#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define gcd __gcd
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define rep1(i, n) for (int i=1; i<=(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
template<typename T, typename cmp = less<T>>
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long f = 0;
    long long flow() {
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

int32_t main() {
    //fastio;
    int m, n; cin>>n>>m;
    vi p(n), c(n); vb lst(n);
    rep(i, n) cin>>p[i];
    rep(i, n) cin>>c[i], --c[i];
    int q; cin>>q;
    vi qry(q);
    rep(i, q) cin>>qry[i], lst[--qry[i]]=1;
    vector<unordered_set<int>> to(n);
    int s=m+n, t=m+n+1;
    Dinic D(m+n+2, s, t);
    rep(i, m) D.add_edge(s, i, 1);
    rep(i, n) D.add_edge(m+i, t, 1);
    rep(i, n) if(!lst[i]&&p[i]<n) to[p[i]].insert(c[i]);
    reverse(all(qry));
    vi ans; ans.reserve(q+1);
    auto add = [&](int v) {
        if(v>=n) return;
        for(auto& u: to[v]) D.add_edge(u, m+v, 1);
    };
    int cur=0; add(0);
    while(cur<n&&D.flow()==cur+1) add(++cur);
    ans.pb(cur);
    for(auto& v: qry) {
        if(p[v]>=n) {ans.pb(cur); continue;}
        else if(p[v]<=cur) {
            if(to[p[v]].find(c[v])==to[p[v]].end()) {
                D.add_edge(c[v], m+p[v], 1);
                to[p[v]].insert(c[v]);
            }
        }
        else to[p[v]].insert(c[v]);
        while(cur<n&&D.flow()==cur+1) add(++cur);
        ans.pb(cur);
    }
    ans.pop_back();
    reverse(all(ans));
    for(auto& v: ans) cout<<v<<endl;
}