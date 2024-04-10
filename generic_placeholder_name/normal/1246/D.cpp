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

constexpr int N=1e5;
int par[N];
int nxt[N];
set<int> adj[N];

pii dfs(int u, int p) {
    par[u]=p;
    pii ans={0, u};
    for(int v: adj[u]) if(v!=p) {
        auto nxt=dfs(v, u);
        ans=max(ans, mp(nxt.fi+1, nxt.se));
    }
    return ans;
}

int32_t main() {
    fastio;
    int n; cin>>n;
    rep1(i, n-1) {
        int p; cin>>p;
        adj[p].insert(i);
    }
    vi ans;
    int u=dfs(0, 0).se;
    while(u) {
        adj[par[u]].erase(u);
        if(adj[par[u]].empty()) u=par[u];
        else ans.pb(u), par[u]=*adj[par[u]].begin();
    }
    rep1(i, n-1) nxt[par[i]]=i;
    int v=0;
    rep(i, n) cout<<v<<' ', v=nxt[v];
    cout<<endl<<ans.size()<<endl;
    reverse(all(ans));
    for(int v: ans) cout<<v<<' '; cout<<endl;
}