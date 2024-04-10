#pragma GCC optimize("O3")

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

constexpr int N=696;
ll dist[N][N];
int edge[N][N];
int lim[N][N];
bitset<N> good[N];

int32_t main() {
    fastio;
    int n, m; cin>>n>>m;
    memset(dist, 0x3f, sizeof(dist));
    memset(edge, 0x3f, sizeof(edge));
    rep(i, n) dist[i][i]=0;
    rep(i, m) {
        int u, v, w; cin>>u>>v>>w; --u, --v;
        edge[u][v]=edge[v][u]=dist[u][v]=dist[v][u]=w;
    }
    rep(k, n) rep(i, n) rep(j, n) dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
    int q; cin>>q;
    rep(i, q) {
        int u, v, l; cin>>u>>v>>l; --u, --v;
        lim[u][v]=lim[v][u]=l;
    }
    rep(v, n) rep(x, n) {
        ll mx=0;
        rep(u, n) mx=max(mx, lim[v][u]-dist[x][u]);
        rep(y, n) if(edge[x][y]!=0x3f3f3f3f&&!good[x][y]) {
            if(edge[x][y]+dist[v][y]<=mx) good[x][y]=good[y][x]=1;
        }
    }
    int ans=0;
    rep(i, n) rep(j, i) ans+=good[i][j];
    cout<<ans<<endl;
}