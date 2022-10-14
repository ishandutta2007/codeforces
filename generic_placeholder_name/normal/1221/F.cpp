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

struct SegTree {
private:
    int n;
    vector<pair<ll, int>> t;
    vector<ll> lz;

    void bld(int v, int l, int r, int p=-1) {
        if(l==r) t[v]={0, l};
        else {
            int m=(l+r)/2;
            bld(v*2, l, m, p);
            bld(v*2+1, m+1, r, p);
            t[v]=max(t[v*2], t[v*2+1]);
        }
    }

    void push(int v) {
        if(!lz[v]) return;
        t[v*2].fi+=lz[v];
        lz[v*2]+=lz[v];
        t[v*2+1].fi+=lz[v];
        lz[v*2+1]+=lz[v];
        lz[v]=0;
    }

    void upd(int ql, int qr, ll val, int v, int l, int r) {
        if(ql>r||qr<l) return;
        if(ql<=l&&qr>=r) {
            t[v].fi+=val;
            lz[v]+=val;
        }
        else {
            push(v);
            int m=(l+r)/2;
            upd(ql, qr, val, v*2, l, m);
            upd(ql, qr, val, v*2+1, m+1, r);
            t[v]=max(t[v*2], t[v*2+1]);
        }
    }

    pair<ll, int> get(int ql, int qr, int v, int l, int r) {
        if(ql>r||qr<l) return {LLONG_MIN, LLONG_MIN};
        if(ql<=l&&qr>=r) return t[v];
        else {
            push(v);
            int m=(l+r)/2;
            return max(get(ql, qr, v*2, l, m), get(ql, qr, v*2+1, m+1, r));
        }
    }

public:
    SegTree(int n): n(n), t(4*n+4), lz(4*n+4, 0) {bld(1, 0, n-1);}
    void upd(int ql, int qr, ll val) {upd(ql, qr, val, 1, 0, n-1);}
    auto get(int ql, int qr) {return get(ql, qr, 1, 0, n-1);}
};

struct custom_hashes {
    inline static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    template<typename T> //should take care of all types that can turn into integers
    size_t operator()(T x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64((uint64_t)x + FIXED_RANDOM);
    }
};

template<typename _F, typename _T> using safe_map=gp_hash_table<_F, _T, custom_hashes>;

//oof did not think they were gonna hack unordered_map
int32_t main() {
    fastio;
    int n; cin>>n;
    vector<array<int, 3>> a(n);
    rep(i, n) {
        rep(j, 3) cin>>a[i][j];
        if(a[i][0]>a[i][1]) swap(a[i][0], a[i][1]);
    }
    vi s;
    auto coordinate_compress = [&]() -> int {
        safe_map<int, int> cmpr;
        for(auto& pt: a) s.pb(pt[0]), s.pb(pt[1]);
        sort(all(s));
        s.resize(unique(all(s))-s.begin());
        rep(i, s.size()) cmpr[s[i]]=i;
        for(auto& pt: a) pt[0]=cmpr[pt[0]], pt[1]=cmpr[pt[1]];
        return s.size();
    };
    int m=coordinate_compress();
    vector<vector<pii>> lf(m); rep(i, n) lf[a[i][1]].eb(a[i][0], a[i][2]);
    SegTree t(m);
    ll mx=0; int x, y;
    rep(i, m) if(i+1==m||s[i+1]>s[i]+1) {x=y=s[i]+1; break;}
    rep(i, m) {
        if(i) t.upd(0, i-1, s[i-1]-s[i]);
        for(auto& [l, c]: lf[i]) t.upd(0, l, c);
        auto cur=t.get(0, i);
        if(cur.fi>mx) mx=cur.fi, x=s[cur.se], y=s[i];
    }
    cout<<mx<<endl<<x<<' '<<x<<' '<<y<<' '<<y<<endl;
}