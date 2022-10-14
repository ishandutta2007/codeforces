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

int32_t main() {
    fastio;
    int n, m; cin>>n>>m;
    vvi adj(n);
    rep(i, m) {
        int u, v; cin>>u>>v; adj[--u].pb(--v); adj[v].pb(u);
    }
    int t[n]; rep(i, n) cin>>t[i];
    int ord[n]; iota(ord, ord+n, 0);
    sort(ord, ord+n, [&](int a, int b){return t[a]<t[b];});
    int cur[n]; rep(i, n) cur[i]=1;
    bool vis[n]; memset(vis, 0, sizeof(vis));
    rep(i, n) {
        int u=ord[i];
        if(cur[u]!=t[u]) return cout<<"-1\n", 0;
        vis[u]=1;
        for(int v: adj[u]) if(!vis[v]) {
            if(cur[v]<cur[u]) return cout<<"-1\n", 0;
            cur[v]=max(cur[v], cur[u]+1);
        }
    }
    rep(i, n) cout<<ord[i]+1<<' '; cout<<endl;
}