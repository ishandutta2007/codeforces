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

constexpr int N = 3000;
int a[N], b[N], c[N];

__attribute__((always_inline)) double cal(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
    const double aa = a * e - b * d, bb = b * g - a * h, cc = d * h - e * g;
    const double z = i * aa + f * bb + c * cc;
    return abs(1. * z * z / (aa * bb * cc)) / 2;
}

int32_t main() {
    fastio;
    int n; cin >> n;
    rep(i, n) cin >> a[i] >> b[i] >> c[i];
    double ans;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                ans += cal(a[i], b[i], c[i], a[j], b[j], c[j], a[k], b[k], c[k]);
            }
        }
    }
    ans /= (n * 1LL * (n - 1) * (n - 2)) / 6;
    cout << setprecision(10) << ans << endl;
}