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

constexpr int N = 105;
int dp[N][N][N];
int C[N][N];

int32_t main() {
    fastio;
    int n, m, k, p; cin >> n >> m >> k >> p;
    auto add = [&](int& a, const ll& b) {a = (a + b) % p;};
    for(int i = 0; i <= n; i++) {
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % p;
    }
    rep(i, m + 1) dp[0][i][0] = 1;
    rep1(i, n) dp[i][1][1] = (i == 1 ? 1 : (dp[i - 1][1][1] * 1LL * i) % p);
    for(int i = 1; i < m; i++) {
        for(int l = 0; l < n; l++) {
            for(int x = 0; x <= l; x++) if(dp[l][i][x]) {
                for(int r = 0; l + r < n; r++) {
                    for(int y = 0; y <= r && x + y <= k; y++) if(dp[r][i][y]) {
                        ll v =  1LL * C[l + r][l] * dp[l][i][x] % p * dp[r][i][y] % p;
                        add(dp[l + r + 1][i + 1][x + y], v);
                    }
                }
            }
        }
    }
    cout << dp[n][m][k] << endl;
}