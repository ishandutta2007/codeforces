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
 
int32_t main() {
    fastio;
    int k, n; cin >> k >> n;
    vi a(n); rep(i, n) cin >> a[i];
    int l = 1, r = k;
    while(l < r) {
        int m = (l + r + 1) / 2;
        static auto check = [&]() -> bool {
            int pos = 0;
            rep(i, n) {
                if(pos > a[i]) return 0;
                pos = max(pos + m, a[i]);
            }
            return pos <= k;
        };
        if(check()) l = m;
        else r = m - 1;
    }
    int ll = l, rr = k;
    while(ll < rr) {
        int m = (ll + rr) / 2;
        static auto check = [&]() -> bool {
            int x = 0, y = 0;
            rep(i, n) {
                if(y + m < a[i]) return 0;
                x = max(x + m, a[i]);
                y = min(y + m, i + 1 == n ? k : a[i + 1]);
            }
            return y == k;
        };
        if(check()) rr = m;
        else ll = m + 1;
    }
    vi x(n), y(n);
    int z = 0, t = 0;
    rep(i, n) {
        z = max(z + l, a[i]);
        t = min(t + rr, i + 1 == n ? k : a[i + 1]);
        x[i] = z, y[i] = t;
    }
    for(int i = n - 2; ~i; i--) {
        x[i] = max(x[i], x[i + 1] - rr);
        y[i] = min(y[i], y[i + 1] - l);
    }
    cout << "0 ";
    rep(i, n - 1) cout << y[i] << endl << y[i] << ' ';
    cout << k << endl;
}