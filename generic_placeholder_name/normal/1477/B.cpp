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

struct segtree {
    int n;
    vi t, lz;

    void bld(const vi& a, int v, int l, int r) {
        if(l==r) t[v]=a[l];
        else {
            int m=(l+r)/2;
            bld(a, v*2, l, m);
            bld(a, v*2+1, m+1, r);
            t[v]=t[v*2]+t[v*2+1];
        }
    }

    segtree(const vi& a): n(a.size()) {
        t.resize(4*n+4);
        lz.resize(4*n+4, -1);
        bld(a, 1, 0, n-1);
    }

    void push(int v, int l, int r) {
        if(~lz[v]) {
            int m=(l+r)/2;
            t[v*2]=lz[v]*(m-l+1);
            t[v*2+1]=lz[v]*(r-m);
            lz[v*2]=lz[v*2+1]=lz[v];
            lz[v]=-1;
        }
    }

    void upd(int ql, int qr, int val, int v, int l, int r) {
        if(ql>r||qr<l) return;
        if(ql<=l&&qr>=r) {
            t[v]=val*(r-l+1);
            lz[v]=val;
        }
        else {
            push(v, l, r);
            int m=(l+r)/2;
            upd(ql, qr, val, v*2, l, m);
            upd(ql, qr, val, v*2+1, m+1, r);
            t[v]=t[v*2]+t[v*2+1];
        }
    }

    int get(int ql, int qr, int v, int l, int r) {
        if(ql>r||qr<l) return 0;
        if(ql<=l&&qr>=r) return t[v];
        else {
            push(v, l, r);
            int m=(l+r)/2;
            return get(ql, qr, v*2, l, m)+get(ql, qr, v*2+1, m+1, r);
        }
    }

    void upd(int ql, int qr, int val) {upd(ql, qr, val, 1, 0, n-1);}
    int get(int ql, int qr) {return get(ql, qr, 1, 0, n-1);}
};

void solve_case() {
    int n, q; cin>>n>>q;
    string _s, _t; cin>>_s>>_t;
    vi s(n), t(n);
    rep(i, n) s[i]=_s[i]-'0';
    rep(i, n) t[i]=_t[i]-'0';
    segtree tr(t);
    vector<pii> qr(q);
    rep(i, q) cin>>qr[i].fi>>qr[i].se, --qr[i].fi, --qr[i].se;
    reverse(all(qr));
    for(auto& [l, r]: qr) {
        int v=tr.get(l, r);
        if((r-l)%2&&v==(r-l+1)/2) return void(puts("NO"));
        if(v<=(r-l)/2) tr.upd(l, r, 0);
        else tr.upd(l, r, 1);
    }
    rep(i, n) if(tr.get(i, i)!=s[i]) return void(puts("NO"));
    puts("YES");
}

int32_t main() {
    fastio;
    int T; cin>>T;
    while(T--) {
        solve_case();
    }
}