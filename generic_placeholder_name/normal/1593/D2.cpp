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

#define gcd rghlrjhg

int gcd(int u, int v) {
    if(!(v * u)) return v ^ u;
    int i = __builtin_ctz(u); u >>= i;
    int j = __builtin_ctz(v); v >>= j;
    int k = min(i, j);
    for(; v; v >>= __builtin_ctz(v)) {
        int m = (v ^ u) & -(v < u);
        u ^= m;
        v ^= m;
        v -= u;
    }
    return u << k;
}

constexpr int N = 40, M = 2e6;
int a[N];

int32_t main() {
    fastio;
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        rep(i, n) cin >> a[i];
        sort(a, a + n);
        int mn = a[0];
        rep(i, n) a[i] -= mn;
        int ans = 0;
        map<int, int> cnt;
        rep(i, n) cnt[a[i]]++;
        for(auto& [_, c]: cnt) if(c > (n - 1) / 2) {cout << "-1\n"; goto end;}
        rep(i, n / 2 + 1) {
            for(int j = i + 1; j < n; j++) {
                vi d;
                int x = a[j] - a[i];
                for(int i = 1; i * i <= x; i++) {
                    if(x % i == 0) {
                        d.pb(i);
                        if(i * i != x) d.pb(x / i);
                    }
                }
                sort(rall(d));
                for(int k = 0; k < d.size() && d[k] > ans; k++) {
                    int x = d[k];
                    int cnt = 0;
                    for(int l = i; l < n; l++) cnt += (a[l] - a[i]) % x == 0;
                    if(cnt > (n - 1) / 2) ans = x;
                }
            }
        }
        cout << ans << endl;
        end:;
    }
}