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

constexpr int N = 1e5 + 5;
constexpr int T = 250;
#define div efeaargr
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
int a[N];
int occ[N];
ll f[N];
ll g[N];

int32_t main() {
    fastio;
    int n; cin >> n;
    rep1(i, n) cin >> a[i];
    ll ans = 0;
    rep1(jmp, n) {
        if(jmp <= T) {
            memset(occ, 0, sizeof(occ));
            memset(f, 0, sizeof(f));
            for(int i = jmp; i <= n; i += jmp) occ[a[i]]++;
            for(int i = N - 1; i > 0; i--) {
                int all = occ[i];
                for(int j = i + i; j < N; j += i) all += occ[j], f[i] -= f[j];
                f[i] += all * 1LL * all;
                g[jmp] += i * 1LL * f[i];
            }
        }
        else {
            ll s = 0, d = 0;
            for(int i = jmp; i <= n; i += jmp) {
                s += a[i];
                for(int j = i + jmp; j <= n; j += jmp) d += gcd(a[i], a[j]);
                g[jmp] = s + (d << 1);
            }
        }
    }
    for(int i = n; i > 0; i--) {
        for(int j = i + i; j <= n; j += i) g[i] -= g[j];
        ans += i * g[i];
    }
    cout << ans % int(1e9 + 7) << endl;
}