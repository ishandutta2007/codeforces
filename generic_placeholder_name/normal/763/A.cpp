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

constexpr int N=1e5+1;
int a[N];
vi adj[N];

pii dfs(int u, int p=-1) {
    pii ans={1, a[u]};
    for(int v: adj[u]) if(v!=p) {
        pii nxt=dfs(v, u);
        if(!nxt.fi||(p!=-1&&nxt.se!=ans.se)) {
            ans.fi=0;
            break;
        }
    }
    return ans;
}

int32_t main() {
    fastio;
    int n; cin>>n;
    rep(i, n-1) {
        int u, v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    rep1(i, n) cin>>a[i];
    rep1(u, n) for(int v: adj[u]) if(a[v]!=a[u]) {
        pii x=dfs(u); if(x.fi) return cout<<"YES\n"<<u<<endl, 0;
        pii y=dfs(v); if(y.fi) return cout<<"YES\n"<<v<<endl, 0;
        return cout<<"NO\n", 0;
    }
    cout<<"YES\n1\n";
}