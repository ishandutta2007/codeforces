#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

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
using ordered_set = tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int N = 1e5 + 5;
vector<pii> adj[N];
ll a[N], b[N];
int l[N], r[N];

void solve_left(int l, int r, int optl, int optr) {
    int m = (l + r) / 2;
    ll ans = a[m]; int idx = m;
    for(int i = optl; i <= min(m, optr); i++) {
        ll x = a[i] + (m - i) * 1LL * (m - i);
        if(ans > x) ans = x, idx = i;
    }
    ::l[m] = idx;
    if(l < m) solve_left(l, m - 1, optl, idx);
    if(m < r) solve_left(m + 1, r, idx, optr);
}

void solve_right(int l, int r, int optl, int optr) {
    int m = (l + r) / 2;
    ll ans = a[m]; int idx = m;
    for(int i = max(m, optl); i <= optr; i++) {
        ll x = a[i] + (m - i) * 1LL * (m - i);
        if(ans > x) ans = x, idx = i;
    }
    ::r[m] = idx;
    if(l < m) solve_right(l, m - 1, optl, idx);
    if(m < r) solve_right(m + 1, r, idx, optr);
}

int32_t main() {
    fastio;
    int n, m, k; cin >> n >> m >> k;
    rep(_, m) {
        int u, v, w; cin >> u >> v >> w; --u, --v;
        adj[u].eb(v, w);
        adj[v].eb(u, w);
    }
    memset(a, 0x3f, sizeof(a));
    a[0] = 0;
    rep(loop, k + 1) {
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        rep(i, n) pq.emplace(a[i], i);
        while(!pq.empty()) {
            auto [chk, u] = pq.top(); pq.pop();
            if(chk != a[u]) continue;
            for(auto& [v, w]: adj[u]) if(a[u] + w < a[v]) {
                a[v] = a[u] + w;
                pq.emplace(a[v], v);
            }
        }
        if(loop == k) break;
        solve_left(0, n - 1, 0, n - 1);
        solve_right(0, n - 1, 0, n - 1);
        rep(i, n) b[i] = min({a[i], a[l[i]] + (i - l[i]) * 1LL * (i - l[i]), a[r[i]] + (i - r[i]) * 1LL * (i - r[i])});
        rep(i, n) a[i] = b[i];
    }
    rep(i, n) cout << a[i] << ' '; cout << endl;
}