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

constexpr int T = 500;
constexpr int N = 2e5 + 2;

int16_t mod[N][T];
int add[T][T];
int event[N];
int day[N];
int x[N], y[N];

int32_t main() {
    fastio;
    int n, m; cin >> n >> m;
    rep(i, n) cin >> x[i] >> y[i];
    rep1(i, m - 1) {
        rep1(j, T - 1) mod[i][j] = mod[i - 1][j] + 1;
        rep1(j, T - 1) mod[i][j] = (mod[i][j] == j) ? 0 : mod[i][j];
    }
    memset(day, -1, sizeof(day));
    int large = 0;
    auto add_small = [&](int id, int d) -> void {
        int tot = x[id] + y[id];
        day[id] = d;
        int s = mod[d][tot];
        for(int i = s; i < tot; i++) add[tot][i] += i - s >= x[id];
        for(int i = 0; i < s; i++) add[tot][i] += i + tot - s >= x[id];
    };
    auto remove_small = [&](int id) -> void {
        int tot = x[id] + y[id];
        int s = mod[day[id]][tot];
        day[id] = -1;
        for(int i = s; i < tot; i++) add[tot][i] -= i - s >= x[id];
        for(int i = 0; i < s; i++) add[tot][i] -= i + tot - s >= x[id];
    };
    auto add_large = [&](int id, int d) -> void {
        int cur_add = 1;
        day[id] = d;
        int pos = d + x[id];
        while(pos < m) {
            event[pos] += cur_add;
            pos += ~cur_add ? y[id] : x[id];
            cur_add = -cur_add;
        }
    };
    auto remove_large = [&](int id, int d) -> void {
        int last_add = 0;
        int cur_add = 1;
        int pos = day[id] + x[id];
        day[id] = -1;
        while(pos < m) {
            if(pos < d) last_add = cur_add;
            event[pos] -= cur_add;
            pos += ~cur_add ? y[id] : x[id];
            cur_add = -cur_add;
        }
        if(last_add == 1) large--;
    };
    rep(i, m) {
        int type, id; cin >> type >> id; --id;
        if(type == 1 && x[id] + y[id] < T) add_small(id, i);
        else if(type == 2 && x[id] + y[id] < T) remove_small(id);
        else if(type == 1 && x[id] + y[id] >= T) add_large(id, i);
        else if(type == 2 && x[id] + y[id] >= T) remove_large(id, i);
        else assert(0);
        large += event[i];
        int ans = large;
        rep1(j, T - 1) ans += add[j][mod[i][j]];
        cout << ans << endl;
    }
}