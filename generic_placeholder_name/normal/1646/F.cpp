#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

constexpr int N = 105;
int occ[N][N];

int32_t main() {
    fastio;
    int n; cin >> n;
    rep(i, n) {
        rep(_, n) {
            int x; cin >> x; --x;
            occ[i][x]++;
        }
    }
    bool ok = 1;
    rep(i, n) ok &= (occ[i][i] == n);
    if(ok) return cout << "0\n", 0;
    vvi ans;
    while(1) {
        bool ok = 1;
        int s = 0;
        rep(i, n) {
            rep(j, n) ok &= (occ[i][j] == 1);
            if(!ok) {s = i; break;}
        }
        if(ok) break;
        vi now(n);
        rep(add, n) {
            int i = (s + add) % n, nxt = (i + 1) % n;
            rep(j, n) if(occ[i][j] > 1) {
                now[i] = j;
                occ[i][j]--;
                occ[nxt][j]++;
                break;
            }
        }
        ans.pb(now);
    }
    vi good(n);
    iota(all(good), 0);
    rep1(dist, n - 1) {
        vi now(n);
        rep(i, n) now[i] = (i + dist) % n;
        while(now != good) {
            ans.pb(now);
            now.insert(now.begin(), now.back());
            now.pop_back();
        }
    }
    cout << ans.size() << endl;
    for(auto& v: ans) {
        for(int x: v) cout << x + 1 << ' ';
        cout << endl;
    }
}