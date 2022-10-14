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

constexpr int N = 100005;
int a[N];

namespace seg {
    constexpr int SEG_SZ = N << 2;
    constexpr int INF = 1e9 + 7;
    int n;

    int mn[SEG_SZ];
    vi s[SEG_SZ];

    vi merge(vi& a, vi& b) {
        vi ans; ans.reserve(a.size() + b.size());
        int aptr = 0, bptr = 0;
        while(aptr < a.size() || bptr < b.size()) {
            if(bptr == b.size() || (aptr != a.size() && a[aptr] < b[bptr])) ans.pb(a[aptr++]);
            else ans.pb(b[bptr++]);
        }
        return ans;
    }

    void bld(int a[], int v = 1, int l = 0, int r = n - 1) {
        mn[v] = INF;
        if(l == r) s[v] = {a[l]};
        else {
            int m = (l + r) / 2;
            bld(a, v * 2, l, m);
            bld(a, v * 2 + 1, m + 1, r);
            s[v] = merge(s[v * 2], s[v * 2 + 1]);
        }
    }

    int now;
    void __upd(int qr, int d, int v = 1, int l = 0, int r = n - 1) {
        if(r <= qr) {
            auto itr = upper_bound(all(s[v]), d);
            if(itr != s[v].end()) mn[v] = min(mn[v], *itr - d);
            if(itr != s[v].begin()) mn[v] = min(mn[v], d - *prev(itr));
            if(now <= mn[v]) return;
            if(l == r) return void(now = min(now, mn[v]));
        }
        int m = (l + r) / 2;
        if(qr > m) __upd(qr, d, v * 2 + 1, m + 1, r);
        __upd(qr, d, v * 2, l, m);
        mn[v] = min(mn[v * 2], mn[v * 2 + 1]);
    }

    void upd(int qr, int d) {now = INF; __upd(qr, d);}

    int query(int ql, int qr, int v = 1, int l = 0, int r = n - 1) {
        if(ql > r || qr < l) return INF;
        if(ql <= l && qr >= r) return mn[v];
        else {
            int m = (l + r) / 2;
            return min(query(ql, qr, v * 2, l, m), query(ql, qr, v * 2 + 1, m + 1, r));
        }
    }
};

int32_t main() {
    fastio;
    int n; cin >> n; seg::n = n;
    rep(i, n) cin >> a[i];
    int q; cin >> q;
    vi ans(q);
    vector<vector<pii>> queries(n);
    rep(i, q) {
        int l, r; cin >> l >> r; --l, --r;
        queries[r].eb(l, i);
    }
    seg::bld(a);
    rep1(i, n - 1) {
        seg::upd(i - 1, a[i]);
        for(auto& [l, id]: queries[i]) ans[id] = seg::query(l, i - 1);
    }
    rep(i, q) cout << ans[i] << endl;
}