#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma 03

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
template<typename _def> using ordered_set=tree<_def, null_type, less<_def>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

vvi adj;
vb vis;
vi h, p;
void dfs(int u, int par=-1) {
    h[u]=par==-1?1:h[par]+1; p[u]=par; vis[u]=1;
    for(int v: adj[u]) if(!vis[v]) dfs(v, u);
}

int32_t main() {
    fastio;
    int q; cin>>q;
    while(q--) {
        int n, m; cin>>n>>m;
        //reset
        adj.assign(n, vi());
        h.assign(n, 0);
        p.assign(n, 0);
        vis.assign(n, 0);
        //input
        rep(i, m) {
            int u, v; cin>>u>>v;
            adj[--u].pb(--v);
            adj[v].pb(u);
        }
        //solve
        auto solve = [&]() -> void {
            dfs(0);
            rep(i, n) if(h[i]>=(n+1)/2) {
                cout<<"PATH\n";
                vi path;
                int cur=i;
                while(cur!=-1) path.pb(cur), cur=p[cur];
                cout<<path.size()<<endl;
                for(auto& it: path) cout<<it+1<<' '; cout<<endl;
                return;
            }
            cout<<"PAIRING\n";
            vvi dep(n);
            rep(i, n) dep[h[i]].pb(i);
            vector<pii> pairs;
            for(auto& d: dep) {
                while(d.size()>=2) {
                    pairs.eb(d[d.size()-1], d[d.size()-2]);
                    d.pop_back(); d.pop_back();

                }
            }
            cout<<pairs.size()<<endl;
            for(auto& it: pairs) cout<<it.fi+1<<' '<<it.se+1<<endl;
            return;
        };
        solve();
    }
}