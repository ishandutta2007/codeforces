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

constexpr int N=2e5+5;
constexpr ll INF=1e18;
int a[N];
vi adj[N];
int par[N];
int dep[N];
vi pos[N];
ll dp[N];

void dfs(int u, int p=-1) {
    if(~p) dep[u]=dep[p]+1;
    par[u]=p;
    pos[dep[u]].pb(u);
    for(int v: adj[u]) if(v!=p) dfs(v, u);
}

void calc(int d) {
    ll max_sub=-INF, max_inc=-INF;
    for(int u: pos[d-1]) {
        ll mn=INF, mx=-INF;
        for(int v: adj[u]) if(v!=par[u]) {
            mn=min(mn, (ll)a[v]);
            mx=max(mx, (ll)a[v]);
        }
        max_sub=max(max_sub, dp[u]-mn);
        max_inc=max(max_inc, dp[u]+mx);
    }
    ll mn=INF, mx=-INF;
    for(int u: pos[d]) mn=min(mn, (ll)a[u]), mx=max(mx, (ll)a[u]);
    for(int u: pos[d]) dp[u]=max({0LL, dp[par[u]]+max(a[u]-mn, mx-a[u]), max_sub+a[u], max_inc-a[u]});
}

void solve_case() {
    int n; cin>>n;
    rep(i, n) adj[i].clear(), pos[i].clear();
    memset(a, 0, n*sizeof(int));
    memset(par, 0, n*sizeof(int));
    memset(dep, 0, n*sizeof(int));
    memset(dp, 0, n*sizeof(ll));
    rep1(i, n-1) {
        int p; cin>>p; --p;
        adj[p].pb(i);
        adj[i].pb(p);
    }
    rep1(i, n-1) cin>>a[i];
    dfs(0);
    int d=*max_element(dep, dep+n);
    rep1(i, d) calc(i);;
    cout<<*max_element(dp, dp+n)<<endl;
}

int32_t main() {
    fastio;
    int T; cin>>T;
    while(T--) solve_case();
}