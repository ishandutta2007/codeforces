#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
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

constexpr int N = 2e5 + 5;
vi adj[N];
int f[N];

int dfs(int u, int p = -1) {
    int id = u;
    for(int v: adj[u]) if(v != p) {
        int x = dfs(v, u);
        if(f[x] > f[id]) id = x;
    }
    f[id]++;
    return id;
}

int32_t main() {
    fastio;
    int n, k; cin >> n >> k;
    rep(_, n - 1) {
        int u, v; cin >> u >> v; --u, --v;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    dfs(0);
    sort(f, f + n, greater<>());
    int d = 0;
    ll ans = -1e18;
    rep(j, k + 1) {
        if(j) d += f[j - 1];
        int l = d - j, r = n - j;
        int a = j * 2 - n;
        while(r - l >= 3) {
            int m1 = (l + l + r) / 3;
            int m2 = (l + r + r) / 3;
            ll xm1 = m1 * 1LL * (m1 + a);
            ll xm2 = m2 * 1LL * (m2 + a);
            if(xm1 < xm2) r = m2;
            else l = m1;
        }
        ll res = 1e18;
        for(int i = l; i <= r; i++) res = min(res, i * 1LL * (i + a));
        ans = max(ans, res);
    }
    cout << ans << endl;
}