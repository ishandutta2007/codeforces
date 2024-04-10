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

constexpr array<ll, 12> pw={1, 42, 1764, 74088, 3111696, 130691232, 5489031744, 230539333248, 9682651996416, 406671383849472, 17080198121677824, 717368321110468608};
struct SegTree { //can support range operations as well, however not required
private:
    int n;
    vll val;
    vll add;
    vll df;

    void push(int v) {
        if(~val[v]) {
            val[v*2]=val[v*2+1]=val[v];
            add[v*2]=add[v*2+1]=0;
            df[v*2]=df[v*2+1]=df[v];
            val[v]=-1;
        }
        else {
            if(!add[v]) return;
            if(~val[v*2]) val[v*2]+=add[v];
            else add[v*2]+=add[v];
            if(~val[v*2+1]) val[v*2+1]+=add[v];
            else add[v*2+1]+=add[v];
            df[v*2]-=add[v];
            df[v*2+1]-=add[v];
            add[v]=0;
        }
    }

    void pull(int v) {
        if(~val[v*2]&&~val[v*2+1]&&val[v*2]==val[v*2+1]) {
            val[v]=val[v*2];
            df[v]=df[v*2];
        }
        else df[v]=min(df[v*2], df[v*2+1]);
    }

    void bld(vi& a, int v, int l, int r) {
        if(l==r) {
            val[v]=a[l];
            df[v]=*lower_bound(begin(pw), end(pw), val[v])-val[v];
        }
        else {
            int m=(l+r)/2;
            bld(a, v*2, l, m);
            bld(a, v*2+1, m+1, r);
            pull(v);
        }
    }

    void set(int ql, int qr, ll x, int v, int l, int r) {
        if(ql>r||qr<l) return;
        if(ql<=l&&qr>=r) {
            val[v]=x;
            add[v]=0;
            df[v]=*lower_bound(begin(pw), end(pw), val[v])-val[v];
        }
        else {
            push(v);
            int m=(l+r)/2;
            set(ql, qr, x, v*2, l, m);
            set(ql, qr, x, v*2+1, m+1, r);
            pull(v);
        }
    }

    void inc(int ql, int qr, ll x, int v, int l, int r) {
        if(ql>r||qr<l) return;
        if(ql<=l&&qr>=r&&(df[v]>=x||~val[v])) {
            if(~val[v]) {
                val[v]+=x;
                if(df[v]>=x) df[v]-=x;
                else df[v]=*lower_bound(begin(pw), end(pw), val[v])-val[v];
            }
            else {
                add[v]+=x;
                df[v]-=x;
            }
        }
        else {
            push(v);
            int m=(l+r)/2;
            inc(ql, qr, x, v*2, l, m);
            inc(ql, qr, x, v*2+1, m+1, r);
            pull(v);
        }
    }

    ll get_df(int ql, int qr, int v, int l, int r) {
        if(ql>r||qr<l) return LLONG_MAX;
        if(ql<=l&&qr>=r) return df[v];
        else {
            push(v);
            int m=(l+r)/2;
            return min(get_df(ql, qr, v*2, l, m), get_df(ql, qr, v*2+1, m+1, r));
        }
    }

    ll get(int pos, int v, int l, int r) {
        if(l==r) return val[v];
        else {
            push(v);
            int m=(l+r)/2;
            if(pos<=m) return get(pos, v*2, l, m);
            else return get(pos, v*2+1, m+1, r);
        }
    }

public:
    SegTree(vi& a): n(a.size()) {
        val.assign(4*n+4, -1);
        add.assign(4*n+4, 0);
        df.resize(4*n+4);
        bld(a, 1, 0, n-1);
    }

    void set(int ql, int qr, ll x) {set(ql, qr, x, 1, 0, n-1);}

    void upd(int ql, int qr, ll x) {
        inc(ql, qr, x, 1, 0, n-1);
        while(get_df(ql, qr, 1, 0, n-1)==0) inc(ql, qr, x, 1, 0, n-1);
    }

    ll get(int pos) {return get(pos, 1, 0, n-1);}
};

int32_t main() {
    fastio;
    int n, q; cin>>n>>q;
    vi a(n);
    rep(i, n) cin>>a[i];
    SegTree t(a);
    while(q--) {
        int type; cin>>type;
        if(type==1) {
            int p; cin>>p;
            cout<<t.get(--p)<<endl;
        }
        else if(type==2) {
            int l, r; ll x; cin>>l>>r>>x;
            t.set(--l, --r, x);
        }
        else {
            assert(type==3);
            int l, r; ll x; cin>>l>>r>>x;
            t.upd(--l, --r, x);
        }
    }
}