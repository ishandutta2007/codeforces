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

//it shouldn't be this long
//but i'm using this to write a neg cycle detection
//so it's long

constexpr int INF=0x3f3f3f3f;
int32_t main() {
    fastio;
    int n, m; cin>>n>>m;
    if(n==1) return puts("YES\n0\n0"), 0;
    vector<vector<pii>> adj(++n);
    rep1(i, n-1) adj[0].eb(i, 0);
    rep(i, m) {
        int u, v, t; cin>>u>>v>>t;
        if(t) {
            adj[u].eb(v, 1);
            adj[v].eb(u, -1);
        }
        else {
            adj[u].eb(v, 1);
            adj[v].eb(u, 1);
        }
    }
    auto bip = [&]() -> bool {
        bool ok=1;
        vi color(n, -1);
        auto dfs = [&](int u, bool c, const auto& self) {
            if(~color[u]) {
                if(color[u]!=c) ok=0;
                return;
            }
            color[u]=c;
            for(auto& [v, _]: adj[u]) self(v, !c, self);
        };
        dfs(1, 0, dfs);
        return ok;
    };
    auto cyc_spfa = [&](int src) -> bool {
        vi dist(n, INF);
        queue<int> q;
        vi par(n, -1);
        vb in(n);
        int iter=0;
        auto cyc = [&]() -> bool {
            vb vis(n), in(n);
            auto dfs = [&](int u, const auto& self) -> bool {
                if(!vis[u]) {
                    vis[u]=1;
                    in[u]=1;
                    if(~par[u]&&!vis[par[u]]&&self(par[u], self)) return 1;
                    else if(~par[u]&&in[par[u]]) return 1;
                }
                in[u]=0;
                return 0;
            };
            rep(i, n) if(!vis[i]&&dfs(i, dfs)) return 1;
            return 0;
        };
        q.push(src); dist[src]=0; in[src]=1;
        while(!q.empty()) {
            int u=q.front(); q.pop();
            in[u]=0;
            iter++;
            if(iter==n) {
                iter=0;
                if(cyc()) return 0;
            }
            for(auto& [v, w]: adj[u]) {
                if(dist[v]>dist[u]+w) {
                    dist[v]=dist[u]+w;
                    par[v]=u;
                    if(!in[v]) q.push(v), in[v]=1;
                }
            }
        }
        return 1;
    };
    vvi dist(n);
    auto spfa = [&](int src, vi& dist) {
        queue<int> q;
        vb in(n);
        dist.assign(n, INF);
        q.push(src); dist[src]=0; in[src]=1;
        while(!q.empty()) {
            int u=q.front(); q.pop();
            in[u]=0;
            for(auto& [v, w]: adj[u]) {
                if(dist[v]>dist[u]+w) {
                    dist[v]=dist[u]+w;
                    if(!in[v]) q.push(v), in[v]=1;
                }
            }
        }
    };
    if(!bip()||!cyc_spfa(0)) return puts("NO"), 0;
    int d=0, id=0;
    rep1(i, n-1) {
        spfa(i, dist[i]);
        int d_i=*max_element(dist[i].begin()+1, dist[i].end())-
                *min_element(dist[i].begin()+1, dist[i].end());
        if(d_i>d) d=d_i, id=i;
    }
    cout<<"YES\n"<<d<<endl;
    rep1(i, n-1) cout<<dist[id][i]+n<<' '; cout<<endl;
}