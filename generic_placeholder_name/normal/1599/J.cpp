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

#pragma GCC optimization("popcnt")

int32_t main() {
    fastio;
    int n; cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    vi p[2];
    rep(i, n) p[a[i] & 1].pb(a[i]);
    unordered_map<int, int> occ;
    rep(i, n) occ[a[i]]++;
    int c = INT_MAX;
    for(auto& [x, v]: occ) if(v > 1) c = x;
    if(n == 2) {
        if(a[0] != a[1]) cout << "NO\n";
        else cout << "YES\n0 " << a[0] << endl;
    }
    else if(c != INT_MAX) {
        vi ans{0};
        for(auto& [x, v]: occ) {
            rep(i, v - (x == c)) {
                ans.pb(x);
            }
        }
        cout << "YES\n";
        for(int x: ans) cout << x << ' '; cout << endl;
    }
    else if(!p[0].empty() && (p[0].size() >= 3 || p[1].size() >= 2)) {
        int x;
        if(p[0].size() >= 3) x = (p[0][1] + p[0][2] - p[0][0]) / 2;
        else x = (p[1][0] + p[1][1] - p[0][0]) / 2;
        vi b{x};
        a.erase(find(all(a), p[0][0]));
        for(int z: a) b.pb(z - x);
        cout << "YES\n";
        for(int x: b) cout << x << ' '; cout << endl;
    }
    else {
        bitset<1000000 * 13 + 1> bs;
        int m = min(n, 26);
        int half = m / 2;
        auto solve = [&](int x, int y) -> void {
            int d = x & y;
            x ^= d; y ^= d;
            vi p, q;
            rep(i, m) if(x >> i & 1) p.pb(a[i]);
            rep(i, m) if(y >> i & 1) q.pb(a[i]);
            vi ans{0};
            int w = 0;
            rep(i, p.size()) {
                w = p[i] - w;
                ans.pb(w);
                w = q[i] - w;
                if(i + 1 != p.size()) ans.pb(w);
            }
            rep(i, n) {
                if(i >= m) ans.pb(a[i]);
                else {
                    if(x >> i & 1) continue;
                    if(y >> i & 1) continue;
                    ans.pb(a[i]);
                }
            }
            cout << "YES\n";
            rep(i, n) cout << ans[i] << ' '; cout << endl;
        };
        for(int i = 0; i < (1 << m); i++){
			if(__builtin_popcount(i) != half) continue;
			int sum = 0;
			for(int j = 0; j < m; j++){
				if(i >> j & 1) sum += a[j];
			}
			if(bs[sum]) {
                for(int k = 0; k < i; k++){
                    if(__builtin_popcount(k) != half) continue;
                    int _sum = 0;
                    for(int j = 0; j < m; j++){
                        if((k >> j) & 1) _sum += a[j];
                    }
                    if(_sum == sum) return solve(i, k), 0;
                }
                assert(0);
			}
			else bs[sum] = 1;
		}
		cout << "NO\n";
    }
}