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

constexpr int MOD = 1e9 + 7;
constexpr int N = 303, K = 1003, Q = 2e5 + 3;

#define I __attribute__((always_inline))
I int add(int a, int b) {return (a += b) >= MOD ? a - MOD : a;}
I int sub(int a, int b) {return (a -= b) < 0 ? a + MOD : a;}
I int mul(int a, int b) {return (a * 1LL * b) % MOD;}
I void sadd(int& a, int b) {if((a += b) >= MOD) a -= MOD;}
#undef I

int dp[K][N];
int ans[Q];

vi adj[N];
int tk[N][N];

int32_t main() {
    fastio;
    int n; cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) {
        int m; cin >> m;
        while(m--) {
            int j; cin >> j; --j;
            adj[j].pb(i);
            tk[i][j] = -1; //for some reason this produces vectorized code
        }
    }
    int q; cin >> q;
    int R = 0;
    vector<array<int, 3>> ops;
    vi act(n, K + 1);
    vi cur = a;
    auto push = [&](int u, int st) -> void {
        auto push = [&](int u, int st, const auto& self) -> void {
            if(st >= act[u]) return;
            act[u] = st;
            ops.pb({u, st, -2});
            for(int v: adj[u]) self(v, st + 1, self);
        };
        push(u, st, push);
    };
    rep(i, n) if(a[i] > 0) push(i, 0);
    rep(_, q) {
        int type; cin >> type;
        if(type == 1) {
            int k, l, r; cin >> k >> l >> r; --l, --r;
            ops.pb({k, l, r}); R++;
        }
        else {
            assert(type == 2);
            int i, x; cin >> i >> x; --i;
            cur[i] += x;
            ops.pb({i, x, -1});
            if(cur[i] > 0 && cur[i] <= x) push(i, 0);
        }
    }
    rep(i, n) {
        int cur_r = 0, cur_a = a[i], cur_act = K;
        memset(dp, 0, sizeof(dp));
        dp[0][i] = 1;
        rep1(t, K - 1) {
            rep(j, i + 1) dp[t][j] = mul(dp[t - 1][j], j + 1);
            rep(j, i) {
                ll xx = 0;
                for(int k = j + 1; k <= i; k++) {
                    xx += tk[j][k] ? dp[t][k] : 0;
                }
                sadd(dp[t][j], xx % MOD);
            }
        }
        rep(t, K) rep1(j, n - 1) sadd(dp[t][j], dp[t][j - 1]);
        for(auto op: ops) {
            if(op[2] == -1) {
                auto [p, x, _] = op;
                if(p == i) cur_a += x;
            }
            else if(op[2] == -2) {
                auto [a, d, _] = op;
                if(a == i) cur_act = d;
            }
            else {
                auto [k, l, r] = op;
                int t = max(k - cur_act, 0);
                int aa = cur_a < 0 ? cur_a + MOD : cur_a;
                sadd(ans[cur_r], mul(aa, sub(dp[t][r], l ? dp[t][l - 1] : 0)));
                cur_r++;
            }
        }
    }
    rep(i, R) cout << ans[i] << endl;
}