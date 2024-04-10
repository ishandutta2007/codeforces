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

constexpr int N = 606;
int edge[N][N];
ll dist[N];
bool vis[N];

int32_t main() {
    fastio;
    int n, m; cin >> n >> m;
    memset(edge, -1, sizeof(edge));
    rep(i, m) {
        int u, v, w; cin >> u >> v >> w;
        edge[u][v] = w;
    }
    rep(i, n) {
        memset(dist, 0x3f, sizeof(dist));
        memset(vis, 0, sizeof(vis));
        rep(j, n) if(~edge[i][j]) dist[j] = edge[i][j];
        auto upd = [&](int j, ll w) -> void {
            if(!vis[j] && dist[j] > w) dist[j] = w;
        };
        rep(_, n) {
            int j = -1;
            rep(k, n) if(!vis[k] && (!~j || dist[j] > dist[k])) j = k;
            vis[j] = 1;
            upd((j + 1) % n, dist[j] + 1);
            rep(k, n) if(~edge[j][k]) upd((dist[j] + k) % n, dist[j] + edge[j][k]);
        }
        dist[i] = 0;
        rep(j, n) cout << dist[j] << " \n"[j + 1 == n];
    }
}