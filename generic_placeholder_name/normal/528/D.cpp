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

mt19937 rng(233);

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

#pragma GCC target ("popcnt")

constexpr int N = 2e5 + 5;

int a[N][4];
bitset<N> b[4], ans;
int S[N], T[N];

int32_t main() {
    fastio;
    int n, m, k; cin >> n >> m >> k;
    string s, t; cin >> s >> t;
    map<char, int> conv = {{'A', 0}, {'G', 1}, {'T', 2}, {'C', 3}};
    rep(i, n) S[i] = conv[s[i]];
    rep(i, m) T[i] = conv[t[i]];
    rep(i, n) ++a[max(0, i - k)][S[i]], --a[min(n, i + k + 1)][S[i]];
    rep(i, n) rep(j, 4) {
        if(i) a[i][j] += a[i - 1][j];
        if(a[i][j]) b[j][i] = 1;
    }
    rep(i, n) ans[i] = 1;
    rep(i, m) ans &= b[T[i]] >> i;
    cout << ans.count() << endl;
}