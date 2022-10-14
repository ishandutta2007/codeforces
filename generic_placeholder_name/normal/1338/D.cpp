//resub from alt
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
#define mp make_pair
#define gcd __gcd
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define rep1(i, n) for (int i=1; i<=(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
template<typename _def> using ordered_set=tree<_def, null_type, less<_def>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

int n;
vvi adj;
vi dp[2];
vi par, ans;
vector<bool> vis;

void upd(pii& a, int n) {
    if(n>a.fi) {
        a.se=a.fi; a.fi=n;
    }
    else if(n>a.se) a.se=n;
}

void DFS(int u) {
    vis[u]=1;
    if(adj[u].size()==1&&vis[adj[u][0]]) {
        dp[0][u]=1; dp[1][u]=0; ans[u]=1;
    }
    else {
        for(int v: adj[u]) if(!vis[v]) {par[v]=u; DFS(v);}
        pii x={0, 0}, y={0, 0};
        for(int v: adj[u]) if(v!=par[u]) {
            ans[u]=max(ans[u], ans[v]);
            upd(x, dp[1][v]); upd(y, max(dp[0][v], dp[1][v]));
            dp[0][u]=max(dp[0][u], 1+dp[1][v]);
            dp[1][u]=max(dp[1][u], (int)adj[u].size()-1-(u!=0)+max(dp[0][v], dp[1][v]));
        }
        ans[u]=max(ans[u], max(1+x.fi+x.se, max((int)adj[u].size()-1+y.fi, (int)adj[u].size()-2+y.fi+y.se)));
    }
}

int32_t main(){
    fastio;
    cin>>n; adj.resize(n); dp[0].assign(n, -1); dp[1].assign(n, -1); vis.assign(n, 0); par.assign(n, -1); ans.assign(n, -1);
    rep(i, n-1) {
        int u, v; cin>>u>>v;
        adj[--u].pb(--v);
        adj[v].pb(u);
    }
    DFS(0);
    cout<<ans[0]<<endl;
}