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

//Trying to cheese a problem with simulated annealing
constexpr int M = 20;
int c[20][20];
int a[20];
int cur, ans;

#define abs svuotbawuomcaoilzs
__attribute__((always_inline)) int abs(int a) {return a < 0 ? -a : a;}

int32_t main() {
    fastio;
    int n, m; cin >> n >> m;
    string s; cin >> s;
    rep(i, n - 1) {
        int a = s[i] - 'a', b = s[i + 1] - 'a';
        c[a][b]++;
        c[b][a]++;
    }
    rep(i, m) c[i][i] = 0;
    iota(a, a + m, 0);
    rep(i, m) rep(j, i) cur += c[i][j] * abs(a[i] - a[j]);
    ans = cur;
    __attribute__((always_inline)) auto rint = [&]() -> int {
        static uniform_int_distribution<int> engine(0, m - 1);
        return engine(rng);
    };
    __attribute__((always_inline)) auto rd = [&]() -> int {
        static uniform_real_distribution<double> engine(0, 1);
        return engine(rng);
    };
    auto st = clock();
    for(double T = 3 * n; (clock() - st) < CLOCKS_PER_SEC - 50; T *= 0.9997) {
        for(int ITERS = 0; ITERS < 100; ITERS++) {
            int l = rint(), r = rint();
            while(l == r) r = rint();
            int nw = cur;
            rep(i, m) if(i != l && i != r) nw += (abs(a[l] - a[i]) - abs(a[r] - a[i])) * (c[r][i] - c[l][i]);
            if(nw < ans) ans = nw;
            if(nw < cur) swap(a[l], a[r]), cur = nw;
        }
        int l = rint(), r = rint();
        while(l == r) r = rint();
        int nw = cur;
        rep(i, m) if(i != l && i != r) nw += (abs(a[l] - a[i]) - abs(a[r] - a[i])) * (c[r][i] - c[l][i]);
        if(nw < ans) ans = nw;
        if(nw < cur || exp((cur - nw) / T) > rd()) swap(a[l], a[r]), cur = nw;
    }
    cout << ans << endl;
}