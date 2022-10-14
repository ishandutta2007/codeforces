#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")

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
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int TL = 5858;
constexpr int N = 100;
constexpr int K = 5;

int a[N][N];
int cur_deg[N];
int max_deg[N];
int u[N], v[N];

int d[N];
int find(int x) {return d[x] < 0 ? x : d[x] = find(d[x]);}
void join(int x, int y) {
   x = find(x), y = find(y);
   if(__builtin_expect(x == y, 0)) return;
   if(d[x] > d[y]) swap(x, y);
   d[x] += d[y]; d[y] = x;
}

int32_t main() {
    fastio;
    int n, k; cin >> n >> k;
    for(int i = 0; i < k; i++) cin >> max_deg[i];
    for(int i = k; i < n; i++) max_deg[i] = n;
    int max_edge = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            cin >> a[i][j];
            max_edge = max(max_edge, a[i][j]);
        }
    }
    int ans = 0;
    for(int i = 0; i < n - 1; i++) {
        u[i] = i, v[i] = n - 1;
        cur_deg[u[i]]++;
        cur_deg[v[i]]++;
        ans += a[i][n - 1];
    }
    auto start = std::chrono::high_resolution_clock::now();
    auto elapsed_time = [&]() -> int {
        auto now = std::chrono::high_resolution_clock::now();
        return chrono::duration_cast<chrono::milliseconds>(now - start).count();
    };
    auto rand_int_n_2 = [&]() -> int {
        static uniform_int_distribution<int> engine(0, n - 2);
        return engine(rng);
    };
    auto rand_int = [&]() -> int {
        static uniform_int_distribution<int> engine(0, n - 1);
        return engine(rng);
    };
    auto rand_real = [&]() -> double {
        static uniform_real_distribution<double> engine(0, 1);
        return engine(rng);
    };
    for(double T = 1e3 * sqrt(100. / max_edge); T >= 1e-7; T *= 0.999995 + 0.000002 * max_edge / 100) {
        int id = rand_int_n_2();
        int cur = ans - a[u[id]][v[id]];
        cur_deg[u[id]]--;
        cur_deg[v[id]]--;
        memset(d, -1, n * sizeof(int));
        for(int i = 0; i < n - 1; i++) if(i != id) join(u[i], v[i]);
        int new_u, new_v;
        do {
            new_u = rand_int();
            new_v = rand_int();
        } while(find(new_u) == find(new_v) || cur_deg[new_u] == max_deg[new_u] || cur_deg[new_v] == max_deg[new_v]);
        if(new_u > new_v) swap(new_u, new_v);
        cur += a[new_u][new_v];
        if(ans > cur || exp((ans - cur) / T) >= rand_real()) {
            ans = cur;
            u[id] = new_u;
            v[id] = new_v;
        }
        cur_deg[u[id]]++;
        cur_deg[v[id]]++;
        if(elapsed_time() >= TL) break;
    }
    cout << ans << endl;
}