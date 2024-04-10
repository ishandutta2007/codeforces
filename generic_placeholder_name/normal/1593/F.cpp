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

constexpr int N = 41;
ll dp[N][N][N][N];

int32_t main() {
    fastio;
    int T; cin >> T;
    while(T--) {
        memset(dp, -1, sizeof(dp));
        int n, a, b; cin >> n >> a >> b;
        string s; cin >> s;
        dp[0][0][0][0] = 0;
        rep(i, n) {
            int x = s[i] - '0';
            rep(j, i + 1) rep(k, a) rep(l, b) {
                if(!~dp[i][j][k][l]) continue;
                ll msk = dp[i][j][k][l];
                dp[i + 1][j + 1][(k * 10 + x) % a][l] = msk ^ (1LL << i);
                dp[i + 1][j][k][(l * 10 + x) % b] = msk;
            }
        }
        ll ans = -1; int df = INT_MAX;
        rep1(j, n - 1) {
            if(!~dp[n][j][0][0]) continue;
            if(df < abs(2 * j - n)) continue;
            assert(__builtin_popcountll(dp[n][j][0][0]) == j);
            df = abs(2 * j - n);
            ans = dp[n][j][0][0];
        }
        if(!~ans) cout << ans;
        else rep(i, n) cout << ((ans >> i) & 1 ? 'R' : 'B');
        cout << endl;
    }
}