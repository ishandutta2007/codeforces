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
template<typename T, typename comp = less<T>>
using ordered_set = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

class SegTree {
    int n;
    vll t, lz;

    void push(int v) {
        if(!lz[v]) return;
        int lc=v*2, rc=v*2+1;
        t[lc]+=lz[v];
        lz[lc]+=lz[v];
        t[rc]+=lz[v];
        lz[rc]+=lz[v];
        lz[v]=0;
    }

    void upd(int ql, int qr, int val, int v, int l, int r) {
        if(ql>r||qr<l) return;
        if(ql<=l&&qr>=r) {
            t[v]+=val;
            lz[v]+=val;
        }
        else {
            push(v);
            int m=(l+r)/2;
            upd(ql, qr, val, v*2, l, m);
            upd(ql, qr, val, v*2+1, m+1, r);
            t[v]=min(t[v*2], t[v*2+1]);
        }
    }

    int bs(int val, int v, int l, int r) {
        if(l==r) return l;
        else {
            push(v);
            int m=(l+r)/2;
            if(t[v*2]<=val) return bs(val, v*2, l, m);
            else return bs(val, v*2+1, m+1, r);
        }
    }

public:
    SegTree() {}
    SegTree(int n): n(n), t(4*n+8), lz(4*n+8) {}

    inline void upd(int l, int r, int val) {upd(l, r, val, 1, 0, n-1);}
    inline int bs(int val) {return bs(val, 1, 0, n-1);}

    ll get(int p, int v, int l, int r) {
        if(l==r) return t[v];
        else {
            push(v);
            int m=(l+r)/2;
            if(p<=m) return get(p, v*2, l, m);
            else return get(p, v*2+1, m+1, r);
        }
    }
};

__attribute__((always_inline)) int md(int a, int b) {return ((a%=b)>=0?a:a+b);}
__attribute__((always_inline)) int dv(int a, int b) {return a/b-(a<0&&a%b);}

array<int, 3> solve(vi& a, int k, int st) {
    int n=a.size();
    SegTree t(n+1);
    t.upd(n, n, INT_MIN);
    array<int, 3> ans={1, st, st};
    stack<array<int, 3>> mx, mn;
    mx.push({0, 0, a[0]});
    mn.push({0, 0, a[0]});
    cc_hash_table<int, int> lst;
    lst[a[0]]=0;
    rep1(i, n-1) {
        if(lst.find(a[i])!=lst.end()) t.upd(0, lst[a[i]], INT_MAX);
        lst[a[i]]=i;
        int mxb=i;
        while(!mx.empty()&&mx.top()[2]<a[i]) {
            auto& seg=mx.top();
            mxb=seg[0];
            t.upd(seg[0], seg[1], a[i]-seg[2]);
            mx.pop();
        }
        if(!mx.empty()&&mx.top()[2]==a[i]) mx.top()[1]=i;
        else mx.push({mxb, i, a[i]});
        int mnb=i;
        while(!mn.empty()&&mn.top()[2]>a[i]) {
            auto& seg=mn.top();
            mnb=seg[0];
            t.upd(seg[0], seg[1], seg[2]-a[i]);
            mn.pop();
        }
        if(!mn.empty()&&mn.top()[2]==a[i]) mn.top()[1]=i;
        else mn.push({mnb, i, a[i]});
        t.upd(0, i-1, -1);
        int lb=t.bs(k);
        ans=max(ans, {i-lb+1, -(lb+st), -(i+st)});
    }
    return ans;
}

int32_t main() {
    fastio;
    int n, k, d; cin>>n>>k>>d;
    int a[n]; rep(i, n) cin>>a[i];
    if(!d) {
        array<int, 3> ans={1, 0, 0};
        int l=0, r=0;
        rep1(i, n-1) {
            if(a[i]!=a[i-1]) {
                ans=max(ans, {r-l+1, -l, -r});
                l=r=i;
            }
            else r=i;
        }
        ans=max(ans, {r-l+1, -l, -r});
        cout<<-ans[1]+1<<' '<<-ans[2]+1<<endl;
    }
    else {
        vi cur;
        int st=0;
        array<int, 3> ans={1, 0, 0};
        rep(i, n) {
            if(i>0&&md(a[i], d)!=md(a[i-1], d)) {
                ans=max(ans, solve(cur, k, st));
                cur.clear();
                st=i;
            }
            cur.pb(dv(a[i], d));
        }
        ans=max(ans, solve(cur, k, st));
        cout<<-ans[1]+1<<' '<<-ans[2]+1<<endl;
    }
}