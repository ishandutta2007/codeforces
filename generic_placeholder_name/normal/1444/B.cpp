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

//wrong modulo ::facepalm::

constexpr int MOD = 998244353;
int exp(int a, int b) {
    int ans = 1;
    for(; b; b >>= 1) {
        if(b & 1) ans = (ans * 1LL * a) % MOD;
        a = (a * 1LL * a) % MOD;
    }
    return ans;
}

int32_t main() {
    fastio;
    int n; cin >> n;
    vi a(n), b(n);
    rep(i, n) cin >> a[i]; sort(all(a));
    rep(i, n) cin >> b[i]; sort(rall(b));
    ll cost = 0; rep(i, n) cost += abs(a[i] - b[i]);
    int factn = 1; rep1(i, n) factn = (factn * 1LL * i) % MOD;
    int fact2n = factn; rep1(i, n) fact2n = (fact2n * 1LL * (n + i)) % MOD;
    int invfactn = exp(factn, MOD - 2);
    int ans = ((((((cost % MOD) * fact2n) % MOD) * invfactn) % MOD) * invfactn) % MOD;
    cout << ans << endl;
}