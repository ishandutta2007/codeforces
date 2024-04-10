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
using ordered_set = tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int N = 2e5 + 5;
tuple<int, int, int> a[N];
vector<pii> lf[N << 1];
gp_hash_table<int, int> conv;

struct SegTree {
private:
    vll mx, lz;
    int n;

    void push(int v) {
        if(!lz[v]) return;
        lz[v*2]+=lz[v];
        lz[v*2+1]+=lz[v];
        mx[v*2]+=lz[v];
        mx[v*2+1]+=lz[v];
        lz[v]=0;
    }

    void upd(int ql, int qr, ll val, int v, int l, int r) {
        if(ql>r||qr<l) return;
        if(ql<=l&&qr>=r) {
            mx[v]+=val;
            lz[v]+=val;
        }
        else {
            push(v);
            int m=(l+r)/2;
            upd(ql, qr, val, v*2, l, m);
            upd(ql, qr, val, v*2+1, m+1, r);
            mx[v]=max(mx[v*2], mx[v*2+1]);
        }
    }

    ll get(int ql, int qr, int v, int l, int r) {
        if(ql>r||qr<l) return LLONG_MIN;
        if(ql<=l&&qr>=r) return mx[v];
        else {
            push(v);
            int m=(l+r)/2;
            return max(get(ql, qr, v*2, l, m), get(ql, qr, v*2+1, m+1, r));
        }
    }

public:
    SegTree(int n): n(n), mx(4*n+4, 0), lz(4*n+4, 0){}
    void upd(int ql, int qr, ll val) {upd(ql, qr, val, 1, 0, n-1);}
    ll get(int ql, int qr) {return get(ql, qr, 1, 0, n-1);}
};

int32_t main() {
    fastio;
    int n; cin >> n;
    vi c;
    rep(i, n) {
        int l, r, x; cin >> l >> r >> x; --x;
        a[i] = {l, r, x};
        c.pb(l), c.pb(r);
    }
    sort(all(c));
    c.erase(unique(all(c)), c.end());
    int m = c.size();
    rep(i, m) conv[c[i]] = i + 1;
    rep(i, n) {
        auto& [l, r, x] = a[i];
        l = conv[l], r = conv[r];
        lf[r].eb(l, x);
    }
    vector<SegTree> t(2, m + 1);
    for(int i = 1; i <= m; i++) {
        for(auto& [l, x]: lf[i]) t[!x].upd(0, l - 1, 1);
        t[1].upd(i, i, t[0].get(0, i - 1));
        t[0].upd(i, i, t[1].get(0, i - 1));
    }
    cout << max(t[0].get(m, m), t[1].get(m, m));
}