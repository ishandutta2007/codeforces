#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma,popcnt")

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

constexpr int MOD = 998244353;

int solve() {
    int n, k; cin >> n >> k;
    vi a(n); rep(i, n) cin >> a[i];
    rep(i, n - k) if(a[i] > i) return 0;
    for(int i = n - k; i < n; i++) if(a[i] > 0) return 0;
    int ans = 1;
    rep1(i, k) ans = (ans * 1LL * i) % MOD;
    for(int i = k; i < n; i++) {
        if(a[i - k] == -1) ans = (ans * 1LL * (i + 1)) % MOD;
        else if(a[i - k] == 0) ans = (ans * 1LL * (k + 1)) % MOD;
    }
    return ans;
}

int32_t main() {
    fastio;
    int T; cin >> T;
    while(T--) cout << solve() << endl;
}