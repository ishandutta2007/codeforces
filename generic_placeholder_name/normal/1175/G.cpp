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

constexpr int N = 2e4 + 5;
constexpr int K = 100;

template<typename T>
void smin(T& a, const T& b) {a = a < b ? a : b;}

template<typename T>
void smax(T& a, const T& b) {a = a > b ? a : b;}

int max_elem(const int* __restrict a, int n) {
    int ans = 0;
    rep(i, n) smax(ans, a[i]);
    return ans;
}

int a[N];
int dp[N][K];
int mx[N], mxw[N];
int now[K];

int32_t main() {
    fastio;
    int n, k; cin >> n >> k;
    rep(i, n) cin >> a[i];
    rep(i, k) dp[0][i] = a[0];
    mx[0] = mxw[0] = a[0];
    rep1(i, n - 1) {
        rep(j, i + 1) smax(mx[j], a[i]);
        rep(j, i + 1) mxw[j] = mx[j] * (i - j + 1);
        dp[i][0] = mxw[0];
        memset(now, 0x3f, (k - 1) * sizeof(int));
        for(int j = i - 1; ~j; j--) {
            rep(l, k - 1) smin(now[l], dp[j][l] + mxw[j + 1]);
            if(!(j & 31) && mxw[j] >= max_elem(now, k - 1)) break;
        }
        rep(l, k - 1) dp[i][l + 1] = now[l];
    }
    cout << dp[n - 1][k - 1] << endl;
}