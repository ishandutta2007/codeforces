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

//since this is a "good" graph
//dinic runs in E * sqrt(V)
//in this case E and V is both n * log A

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

    long long flow() {
        long long f = 0;
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
    constexpr int T=35000;
    bool isprime[T];
    int primes[T];
    int pr_cnt=0;
    memset(isprime, true, sizeof(isprime));
    for(int i=2; i*i<T; i++) if(isprime[i]) {
        primes[pr_cnt++]=i;
        for(int j=i*i; j<T; j+=i) isprime[j]=0;
    }
    fastio;
    int n, m; cin>>n>>m;
    vector<vector<tuple<int, int, int>>> divi(n);
    vector<tuple<int, int, int>> addt_edges;
    vi a(n);
    rep(i, n) cin>>a[i];
    int sz=n+2;
    rep(i, n) {
        int cur=a[i];
        rep(j, pr_cnt) if(cur%primes[j]==0) {
            int cnt=0;
            while(cur%primes[j]==0) {
                cnt++;
                cur/=primes[j];
            }
            divi[i].eb(primes[j], cnt, sz++);
        }
        if(cur!=1) divi[i].eb(cur, 1, sz++);
    }
    rep1(j, m) {
        int u, v; cin>>u>>v; --u, --v;
        if(v&1) swap(u, v);
        for(auto& [x, _, pos]: divi[u]) {
            auto itr=lower_bound(all(divi[v]), make_tuple(x, 0, 0));
            if(itr!=divi[v].end()&&get<0>(*itr)==x) {
                addt_edges.eb(pos, get<2>(*itr), get<1>(*itr));
            }
        }
    }
    constexpr int INF=1e9+7;
    int s=n, t=n+1;
    Dinic D(sz, s, t);
    rep(i, n) {
        if(i&1) {
            D.add_edge(s, i, INF);
            for(auto& [_, c, p]: divi[i]) {
                D.add_edge(i, p, c);
            }
        }
        else {
            D.add_edge(i, t, INF);
            for(auto& [_, c, p]: divi[i]) {
                D.add_edge(p, i, c);
            }
        }
    }
    for(auto& [u, v, w]: addt_edges) {
        D.add_edge(u, v, w);
    }
    cout<<D.flow()<<endl;
}