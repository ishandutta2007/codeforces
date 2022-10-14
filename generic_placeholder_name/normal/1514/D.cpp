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

constexpr int N = 3e5 + 5;

int n;
int a[N];

vi pos[N];

int cnt(int x, int l, int r) {
    return upper_bound(all(pos[x]), r) - lower_bound(all(pos[x]), l);
}

const pii id = {INT_MIN, 0};
pii T[N << 2];

pii combine(const pii& x, const pii& y) {
    if(x == id || y == id) return max(x, y);
    pii ans;
    if(x.fi == y.fi) {
        ans.fi = x.fi;
        ans.se = x.se + y.se;
    }
    else if(x.se > y.se) {
        ans.fi = x.fi;
        ans.se = x.se - y.se;
    }
    else {
        ans.fi = y.fi;
        ans.se = y.se - x.se;
    }
    return ans;
}

void seg_bld(int v = 1, int l = 0, int r = n - 1) {
    if(l == r) T[v] = mp(a[l], 1);
    else {
        int m = (l + r) >> 1;
        seg_bld(v * 2, l, m);
        seg_bld(v * 2 + 1, m + 1, r);
        T[v] = combine(T[v * 2], T[v * 2 + 1]);
    }
}

pii seg_query(int ql, int qr, int v = 1, int l = 0, int r = n - 1) {
    if(ql > r || qr < l) return id;
    if(ql <= l && qr >= r) return T[v];
    else {
        int m = (l + r) >> 1;
        return combine(seg_query(ql, qr, v * 2, l, m), seg_query(ql, qr, v * 2 + 1, m + 1, r));
    }
}

void bld() {
    rep(i, n) pos[--a[i]].pb(i);
    seg_bld();
}

int query(int l, int r) {
    int x = seg_query(l, r).fi;
    int c = cnt(x, l, r);
    return max((c << 1) - (r - l + 1), 1);
}

int32_t main() {
    fastio;
    int q; cin >> n >> q;
    rep(i, n) cin >> a[i];
    bld();
    while(q--) {
        int l, r; cin >> l >> r; --l, --r;
        cout << query(l, r) << endl;
    }
}