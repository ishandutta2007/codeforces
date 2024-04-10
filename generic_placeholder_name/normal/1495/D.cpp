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

constexpr int MOD = 998244353;
constexpr int N = 420, M = 696;
int16_t dist[N][N];
int ans[N][N];
int16_t lst[M << 1], to[M << 1], nxt[M << 1];

int sz;
void add_edge(int u, int v) {
    dist[u][v] = 1;
    nxt[++sz] = lst[u];
    to[sz] = v;
    lst[u] = sz;
}

int32_t main() {
    fastio;
    int n, m; cin >> n >> m;
    memset(dist, 0x3f, sizeof(dist));
    rep(i, m) {
        int u, v; cin >> u >> v;
        --u, --v;
        add_edge(u, v);
        add_edge(v, u);
    }
    rep(i, n) dist[i][i] = 0;
    rep(k, n) rep(i, n) rep(j, n) dist[i][j] = min(dist[i][j], int16_t(dist[i][k] + dist[k][j]));
    rep(j, n) rep(i, j + 1) {
        int cnt = 0;
        rep(k, n) cnt += (dist[i][k] + dist[j][k] == dist[i][j]);
        if(cnt != dist[i][j] + 1) continue;
        int res = 1;
        rep(k, n) if(dist[i][k] + dist[j][k] != dist[i][j]) {
            int flag = 0;
            for(int16_t id = lst[k]; id; id = nxt[id]) {
                int16_t l = to[id];
                flag += (dist[i][l] == dist[i][k] - 1 && dist[j][l] == dist[j][k] - 1);
            }
            res = (res * 1LL * flag) % MOD;
            if(!res) break;
        }
        ans[i][j] = res;
    }
    rep(i, n) rep(j, i) ans[i][j] = ans[j][i];
    rep(i, n) rep(j, n) cout << ans[i][j] << " \n"[j + 1 == n];
}