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

//WHY DOES THIS PROBLEM USE A DIFFERENT DEFINITION OF CONTAINS THAN ALL OTHER PROBLEMS
//WHAT THE FUCK IS THIS SHIT
//GET THE FUCK OUT OF HERE

int32_t main() {
    fastio;
    int n; cin >> n; n /= 3;
    array<vector<pii>, 3> pt;
    rep(i, 3 * n) {
        int x, y, c; cin >> x >> y >> c;
        pt[--c].eb(x, y);
    }
    auto _chk = [&](int k, bool rx, bool ry, bool fl) -> bool {
        auto p = pt;
        rep(i, 3) rep(j, n) {
            if(fl) swap(p[i][j].fi, p[i][j].se);
            if(rx) p[i][j].fi = -p[i][j].fi;
            if(ry) p[i][j].se = -p[i][j].se;
        }
        array<vi, 3> x, y;
        rep(i, 3) {
            x[i].reserve(n);
            for(auto& [a, b]: p[i]) x[i].pb(a);
        }
        int c[3] = {0, 1, 2};
        //left-right
        do {
            nth_element(x[c[0]].begin(), x[c[0]].begin() + (k - 1), x[c[0]].end());
            int x1 = x[c[0]][k - 1];
            int s = 0;
            rep(i, n) s += x[c[1]][i] <= x1;
            if(s + k > n) continue;
            nth_element(x[c[1]].begin(), x[c[1]].begin() + (s + k - 1), x[c[1]].end());
            int x2 = x[c[1]][s + k - 1];
            s = 0;
            rep(i, n) s += x[c[2]][i] <= x2;
            if(s + k <= n) return 1;
        } while(next_permutation(c, c + 3));
        //left-up-down
        iota(c, c + 3, 0);
        do {
            nth_element(x[c[0]].begin(), x[c[0]].begin() + (k - 1), x[c[0]].end());
            int x1 = x[c[0]][k - 1];
            int s = 0;
            rep(i, n) s += x[c[1]][i] <= x1;
            if(s + k > n) continue;
            y[c[1]].clear();
            for(auto& [a, b]: p[c[1]]) if(a > x1) y[c[1]].pb(b);
            nth_element(y[c[1]].begin(), y[c[1]].begin() + (k - 1), y[c[1]].end());
            int y1 = y[c[1]][k - 1];
            s = 0;
            for(auto& [a, b]: p[c[2]]) s += (a > x1 && b > y1);
            if(s >= k) return 1;
        } while(next_permutation(c, c + 3));
        return 0;
    };
    auto chk = [&](int k) -> bool {
        for(bool x: {0, 1}) {
            for(bool y: {0, 1}) {
                for(bool z: {0, 1}) {
                    if(_chk(k, x, y, z)) return 1;
                }
            }
        }
        return 0;
    };
    int l = 1, r = n;
    while(l < r) {
        int m = (l + r + 1) / 2;
        if(chk(m)) l = m;
        else r = m - 1;
    }
    cout << 3 * l << endl;
}