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
int a[N];
int b[N];
vector<tuple<int, int, int>> q[N];
int ans[N];

int32_t main() {
    fastio;
    int n; cin >> n;
    rep(i, n) cin >> a[i];
    int m; cin >> m;
    rep(i, m) {
        int l, r, w; cin >> l >> r >> w;
        q[--w].eb(--l, --r, i);
    }
    memset(b, 0x3f, sizeof(b));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i; j++) {
            b[j] = b[j] < a[i + j] ? b[j] : a[i + j];
        }
        for(auto& [l, r, idx]: q[i]) {
            int v = 0;
            for(int j = l; j <= r - i; j++) v = v < b[j] ? b[j] : v;
            ans[idx] = v;
        }
    }
    rep(i, m) cout << ans[i] << endl;
}