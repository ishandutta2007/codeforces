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
        }
    }

    ll get(int ql, int qr, int v, int l, int r) {
        if(ql>r||qr<l) return LLONG_MAX;
        if(ql<=l&&qr>=r) return mn[v];
        else {
            push(v);
            int m=(l+r)/2;
            return min(get(ql, qr, v*2, l, m), get(ql, qr, v*2+1, m+1, r));
        }
    }

public:
    SegTree(int n): n(n), mn(4*n+4, 0), lz(4*n+4, 0){}
    void upd(int ql, int qr, ll val) {upd(ql, qr, val, 1, 0, n-1);}
    ll get(int ql, int qr) {return get(ql, qr, 1, 0, n-1);}
};

int32_t main() {
    fastio;
    int T; cin >> T;
    while(T--) {
        int n, m; cin >> n >> m;
        vi a(n); rep(i, n) cin >> a[i];
        sort(all(a));
        SegTree t(n + 1);
        rep(i, n) t.upd(i, i, n - i);
        vvi b(m);
        vll sum(m);
        vi pos(m);
        rep(i, m) {
            int x; cin >> x;
            b[i].resize(x);
            for(auto& x: b[i]) {
                cin >> x;
                sum[i] += x;
            }
            pos[i] = lower_bound(all(a), (int)ceil(sum[i] * 1. / b[i].size())) - a.begin();
            t.upd(0, pos[i], -1);
        }
        rep(i, m) {
            t.upd(0, pos[i], 1);
            for(auto& x: b[i]) {
                int y = ceil((sum[i] - x) * 1. / (b[i].size() - 1));
                int p = lower_bound(all(a), y) - a.begin();
                t.upd(0, p, -1);
                if(t.get(0, n) >= 0) cout << "1";
                else cout << "0";
                t.upd(0, p, 1);
            }
            t.upd(0, pos[i], -1);
        }
        cout << endl;
    }
}