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

//new ver

uint f(uint x) {
    uint l = 1u << (__lg(x) + !!(x & (x - 1)));
    return l - x;
}

int g(uint x, uint y) {
    int ans = 0;
    while(x != y) {
        if(x > y) swap(x, y);
        y = f(y);
        ans++;
    }
    return ans;
}

int32_t main() {
    fastio;
    int n; cin >> n;
    vector<uint> a(n); rep(i, n) cin >> a[i];
    pii mx = {0, 0};
    rep1(i, n - 1) mx = max(mx, mp(g(a[0], a[i]), i));
    int id = mx.se;
    mx = {0, 0};
    rep(i, n) if(i != id) mx = max(mx, mp(g(a[id], a[i]), i));
    cout << id + 1 << ' ' << mx.se + 1 << ' ' << g(a[id], a[mx.se]) << endl;
}