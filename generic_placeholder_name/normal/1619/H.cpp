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

constexpr int N = 100005;
constexpr int T = 130;
int nxt[N];
int prv[N];
int nxtT[N];

int32_t main() {
    fastio;
    int n, q; cin >> n >> q;
    rep1(i, n) {
        cin >> nxt[i];
        prv[nxt[i]] = i;
    }
    if(n <= 2 * T) {
        while(q--) {
            int t; cin >> t;
            if(t == 1) {
                int x, y; cin >> x >> y;
                swap(nxt[x], nxt[y]);
            }
            else {
                int i, x; cin >> i >> x;
                rep(_, x) i = nxt[i];
                cout << i << endl;
            }
        }
    }
    else {
        rep1(i, n) {
            int j = i;
            rep(_, T) j = nxt[j];
            nxtT[i] = j;
        }
        while(q--) {
            int t; cin >> t;
            if(t == 1) {
                int x, y; cin >> x >> y;
                swap(nxt[x], nxt[y]);
                prv[nxt[x]] = x;
                prv[nxt[y]] = y;
                static const auto prop = [&](int i) -> void {
                    int j = i;
                    rep(_, T - 1) j = prv[j];
                    rep(_, T + 1) {
                        nxtT[j] = nxt[i];
                        j = nxt[j];
                        i = nxt[i];
                    }
                };
                prop(x);
                prop(y);
            }
            else {
                int i, x; cin >> i >> x;
                rep(_, x / T) i = nxtT[i];
                rep(_, x % T) i = nxt[i];
                cout << i << endl;
            }
        }
    }
}