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

struct SegTree {
private:
    vll mn, lz;
    vi cnt;
    int n;

    void push(int v) {
        if(!lz[v]) return;
        lz[v*2]+=lz[v];
        lz[v*2+1]+=lz[v];
        mn[v*2]+=lz[v];
        mn[v*2+1]+=lz[v];
        lz[v]=0;
    }

    void upd(int ql, int qr, ll val, int v, int l, int r) {
        if(ql>r||qr<l) return;
        if(ql<=l&&qr>=r) {
            mn[v]+=val;
            lz[v]+=val;
        }
        else {
            push(v);
            int m=(l+r)/2;
            upd(ql, qr, val, v*2, l, m);
            upd(ql, qr, val, v*2+1, m+1, r);
            mn[v]=min(mn[v*2], mn[v*2+1]);
            if(mn[v * 2] < mn[v * 2 + 1]) cnt[v] = cnt[v * 2];
            else if(mn[v * 2] > mn[v * 2 + 1]) cnt[v] = cnt[v * 2 + 1];
            else cnt[v] = cnt[v * 2] + cnt[v * 2 + 1];
        }
    }

    pair<ll, int> get(int ql, int qr, int v, int l, int r) {
        if(ql>r||qr<l) return mp(LLONG_MAX, 0);
        if(ql<=l&&qr>=r) return mp(mn[v], cnt[v]);
        else {
            push(v);
            int m=(l+r)/2;
            auto x = get(ql, qr, v * 2, l, m), y = get(ql, qr, v * 2 + 1, m + 1, r);
            if(x.fi < y.fi) return x;
            else if(x.fi > y.fi) return y;
            else return mp(x.fi, x.se + y.se);
        }
    }

    int bs(int x, int v, int l, int r) {
        if(l == r) return l;
        push(v);
        int m = (l + r) / 2;
        if(mn[v * 2 + 1] < x) return bs(x, v * 2 + 1, m + 1, r);
        else return bs(x, v * 2, l, m);
    }

    void bld_cnt(int v, int l, int r) {
        cnt[v] = r - l + 1;
        if(l != r) {
            int m = (l + r) / 2;
            bld_cnt(v * 2, l, m);
            bld_cnt(v * 2 + 1, m + 1, r);
        }
    }

public:
    SegTree(int n): n(n), mn(4*n+4, 0), lz(4*n+4, 0) {cnt.resize(4 * n + 4); bld_cnt(1, 0, n - 1);}
    void upd(int ql, int qr, ll val) {upd(ql, qr, val, 1, 0, n-1);}
    pair<ll, int> get(int ql, int qr) {return get(ql, qr, 1, 0, n-1);}
    int bs(int x) {
        if(mn[1] >= x) return -1;
        else return bs(x, 1, 0, n - 1);
    }
};

int32_t main() {
    fastio;
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        vi a(n); rep(i, n) cin >> a[i];
        ll ans = 0;
        rep(i, n) ans += a[i] == 0;
        if(n == 1) {cout << ans << endl; continue;}
        SegTree even((n + 1) / 2), odd(n / 2);
        rep(i, n) {
            if(i & 1) odd.upd(0, i / 2, a[i]), even.upd(0, i / 2, -a[i]);
            else {
                even.upd(0, i / 2, a[i]);
                if(i > 1) odd.upd(0, i / 2 - 1, -a[i]);
            }
            int b = max(max(even.bs(0) * 2, odd.bs(0) * 2 + 1) + 1, 0);
            if(i && (b + 1) / 2 <= (i - 1) / 2) {
                auto x = even.get((b + 1) / 2, (i - 1) / 2);
                if(!x.fi) ans += x.se;
            }
            if(b / 2 <= i / 2 - 1) {
                auto x = odd.get(b / 2, i / 2 - 1);
                if(!x.fi) ans += x.se;
            }
        }
        cout << ans << endl;
    }
}