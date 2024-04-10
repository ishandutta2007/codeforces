#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

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

constexpr int N=50005;
int a[N];
int par[N];
vi adj[N];
int tin[N], tout[N], lvl[N], lst[N];
int flat_a[N], flat_lvl[N];

void dfs(int u) {
    static int t=0;
    tin[u]=t++;
    if(u) lvl[u]=lvl[par[u]]+1;
    for(int v: adj[u]) dfs(v);
    tout[u]=t-1;
}

int32_t main() {
    fastio;
    int n, q; cin>>n>>q;
    rep(i, n) cin>>a[i];
    rep1(i, n-1) {cin>>par[i]; adj[--par[i]].pb(i);}
    dfs(0);
    rep(i, n) flat_a[tin[i]]=a[i], flat_lvl[tin[i]]=lvl[i];
    rep1(t, q) {
        int x; cin>>x; --x;
        int sum=0, cnt=0;
        for(int i=tin[x]; i<=tout[x]; i++) {
            if(lst[i]<=t) {
                lst[i]=t+flat_a[i];
                cnt++;
                sum+=flat_lvl[i]-lvl[x];
            }
        }
        cout<<sum<<' '<<cnt<<endl;
    }
}