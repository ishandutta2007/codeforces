#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

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
template<typename _def> using ordered_set=tree<_def, null_type, less<_def>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int p=345679, inv=456868949, MOD=1e9+9;
inline int add(int a, int b) {a+=b; if(a>=MOD) a-=MOD; return a;}
inline int sub(int a, int b) {return add(a, MOD-b);}
inline int mul(int a, int b) {return (a*1LL*b)%MOD;}

constexpr int N=200001;
struct SegTree {
    array<int, 4*N+4> t, lz;

    SegTree() {t.fill(0), lz.fill(1);}

    void push(int v) {
        if(lz[v]==1) return;
        t[v*2]=mul(t[v*2], lz[v]);
        lz[v*2]=mul(lz[v*2], lz[v]);
        t[v*2+1]=mul(t[v*2+1], lz[v]);
        lz[v*2+1]=mul(lz[v*2+1], lz[v]);
        lz[v]=1;
    }

    void upd(int ql, int qr, int val, int v, int l, int r) {
        if(ql>r||qr<l) return;
        if(ql<=l&&qr>=r) {
            t[v]=mul(t[v], val);
            lz[v]=mul(lz[v], val);
        }
        else {
            push(v);
            int m=(l+r)/2;
            upd(ql, qr, val, v*2, l, m);
            upd(ql, qr, val, v*2+1, m+1, r);
            t[v]=add(t[v*2], t[v*2+1]);
        }
    }
    inline void upd(int ql, int qr, int val) {upd(ql, qr, val, 1, 1, N);}

    void set(int pos, int val, int v, int l, int r) {
        if(l==r) t[v]=val;
        else {
            push(v);
            int m=(l+r)/2;
            if(pos<=m) set(pos, val, v*2, l, m);
            else set(pos, val, v*2+1, m+1, r);
            t[v]=add(t[v*2], t[v*2+1]);
        }
    }
    inline void set(int pos, int val) {set(pos, val, 1, 1, N);}

    int get(int ql, int qr, int v, int l, int r) {
        if(ql>r||qr<l) return 0;
        if(ql<=l&&qr>=r) return t[v];
        else {
            push(v);
            int m=(l+r)/2;
            return add(get(ql, qr, v*2, l, m), get(ql, qr, v*2+1, m+1, r));
        }
    }
    inline int get(int ql, int qr) {return get(ql, qr, 1, 1, N);}
} T;

int32_t main() {
    fastio;
    int n, m; cin>>n>>m;
    int a[n], b[m];
    int pw[n+1]; pw[0]=1; rep1(i, n) pw[i]=mul(pw[i-1], p);
    rep(i, n) cin>>a[i]; rep(i, m) cin>>b[i];
    int step=0, cur=0;
    rep(i, n) {
        step=add(step, pw[i]);
        cur=add(cur, mul(a[i], pw[i]));
    }
    int ans=0;
    int pos[m+1];
    rep(i, m) pos[b[i]]=i+1;
    ordered_set<int> cur_pos;
    rep1(i, n) cur_pos.insert(pos[i]);
    rep1(i, n) T.set(pos[i], mul(i, pw[cur_pos.order_of_key(pos[i])]));
    ans+=(T.get(1, N)==cur);
    for(int i=n+1; i<=m; i++) {
        cur=add(cur, step);
        cur_pos.erase(pos[i-n]);
        T.set(pos[i-n], 0);
        T.upd(pos[i-n]+1, N, inv);
        cur_pos.insert(pos[i]);
        T.set(pos[i], mul(i, pw[cur_pos.order_of_key(pos[i])]));
        T.upd(pos[i]+1, N, p);
        ans+=(T.get(1, N)==cur);
    }
    cout<<ans<<endl;
}