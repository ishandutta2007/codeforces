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
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

ll solve_two(const vi& a) {
    int n = a.size();
    vector<array<ll, 2>> dp(n);
    dp[1][0] = a[0] + a[1];
    dp[1][1] = -(a[0] + a[1]);
    for(int i = 2; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + a[i];
        dp[i][1] = max(dp[i - 1][0] - 2 * a[i - 1],  dp[i - 1][1] + 2 * a[i - 1]) - a[i];
    }
    return max(dp[n - 1][0], dp[n - 1][1]);
}

int32_t main() {
    fastio;
    int T; cin >> T;
    while(T--) {
        int n, m; cin >> n >> m;
        vi a(n); rep(i, n) cin >> a[i];
        int g = 0;
        while(m--) {
            int x; cin >> x;
            g = gcd(g, x);
        }
        if(g == 1) {
            ll ans = 0;
            rep(i, n) ans += abs(a[i]);
            cout << ans << endl;
        }
        else {
            vvi v(g);
            rep(i, n) v[i % g].pb(a[i]);
            ll ans = 0;
            rep(i, g) ans += solve_two(v[i]);
            rep(i, g) v[i][0] = -v[i][0];
            ll ans_rev = 0;
            rep(i, g) ans_rev += solve_two(v[i]);
            cout << max(ans, ans_rev) << endl;
        }
    }
}