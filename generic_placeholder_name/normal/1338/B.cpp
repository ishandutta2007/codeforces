//resub from alt
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma 03

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

vi dist;
vector<bool> vis;
vvi adj;
int n;

void DFS(int u, int d) {
    dist[u]=d; vis[u]=1;
    for(int v: adj[u]) if(!vis[v]) DFS(v, d+1);
}

int32_t main(){
    fastio;
    cin>>n; adj.resize(n); vis.assign(n, 0); dist.assign(n, -1);
    rep(i, n-1) {
        int u, v; cin>>u>>v;
        adj[--u].pb(--v); adj[v].pb(u);
    }
    DFS(0, 0);
    bool c[2]={0};
    rep(i, n) if(adj[i].size()==1) c[dist[i]%2]=1;
    if(c[0]&c[1]) cout<<3<<' '; else cout<<1<<' ';
    bool excl[n]={0};
    int ans=n-1;
    rep(i, n) if(adj[i].size()==1) {
        excl[adj[i][0]]=1; ans--;
    }
    rep(i, n) if(excl[i]) ans++;
    cout<<ans<<endl;
}