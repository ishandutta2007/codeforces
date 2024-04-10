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


vector<int> assignment;

template<typename T>
int64_t hungarian(vector<vector<T>> costs) {
    static constexpr int64_t INF64 = 1e18;

    int n = int(costs.size());
    int m = costs.empty() ? 0 : int(costs[0].size());

    if (n > m) {
        vector<vector<T>> new_costs(m, vector<T>(n));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                new_costs[j][i] = costs[i][j];

        swap(costs, new_costs);
        swap(n, m);
    }

    vector<int64_t> u(n + 1), v(m + 1);
    vector<int> p(m + 1), way(m + 1);

    for (int i = 1; i <= n; i++) {
        vector<int64_t> min_v(m + 1, INF64);
        vector<bool> used(m + 1, false);
        p[0] = i;
        int j0 = 0;

        do {
            used[j0] = true;
            int i0 = p[j0], j1 = 0;
            int64_t delta = INF64;

            for (int j = 1; j <= m; j++)
                if (!used[j]) {
                    int64_t cur = costs[i0 - 1][j - 1] - u[i0] - v[j];

                    if (cur < min_v[j]) {
                        min_v[j] = cur;
                        way[j] = j0;
                    }

                    if (min_v[j] < delta) {
                        delta = min_v[j];
                        j1 = j;
                    }
                }

            for (int j = 0; j <= m; j++)
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    min_v[j] -= delta;
                }

            j0 = j1;
        } while (p[j0] != 0);

        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0 != 0);
    }

    // Note that p[j] is the row assignment of column j (both 1-based). If p[j] = 0, the column is unassigned.
    assignment = p;
    return -v[0];
}

void solve_case() {
    int n, k;
    cin >> n >> k;
    vi a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    vvi cost(n, vi(n, 0));
    rep(i, n) rep(j, n) {
        if(j < k) cost[i][j] = - (a[i] + j * b[i]);
        else cost[i][j] = - ((k - 1) * b[i]);
    }
    int res = -hungarian(cost);
    vi ans;
    for(int i = 1; i < k; i++) ans.pb(assignment[i]);
    for(int i = k + 1; i <= n; i++) ans.pb(assignment[i]), ans.pb(-assignment[i]);
    ans.pb(assignment[k]);
    cout << ans.size() << endl;
    for(int v: ans) cout << v << ' '; cout << endl;
}

int32_t main() {
    fastio;
    int T; cin >> T;
    while(T--) solve_case();
}