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

constexpr int N=3e5+5;
int n;
constexpr int k=5;

struct Node {
    pii lst[k];
    int sz;

    Node(): sz(0) {}
    Node(int id, int cnt): sz(1) {lst[0]={cnt, id};}

    inline bool empty() const {return !sz;}
    inline void clear() {sz=0; memset(lst, 0, sizeof(lst));}

    void operator = (const Node& oth) {
        sz=oth.sz;
        memcpy(lst, oth.lst, k*sizeof(pii));
    }

    friend Node operator + (const Node& a, const Node& b) { //O(n^2) since n is small
        Node c;
        int csz=a.sz;
        pii cur[2*k];
        memcpy(cur, a.lst, k*sizeof(pii));
        for(int i=0; i<b.sz; i++) {
            bool ok=0;
            for(int j=0; j<a.sz; j++) {
                if(cur[j].se==b.lst[i].se) {
                    cur[j].fi+=b.lst[i].fi;
                    ok=1; break;
                }
            }
            if(!ok) cur[csz++]=b.lst[i];
        }
        sort(cur, cur+csz, greater<pii>());
        if(csz>k) {
            for(int i=csz-1; i>=k; i--) {
                rep(j, i) cur[j].fi-=cur[i].fi;
            }
            c.sz=k;
        }
        else c.sz=csz;
        memcpy(c.lst, cur, k*sizeof(pii));
        return c;
    }
};

Node t[4*N+4];
int lz[4*N+4];
int a[N];
ordered_set<int> p[N];

void push(int v, int l, int r) {
    if(!lz[v]) return;
    const int lc=v*2, rc=v*2+1;
    const int m=(l+r)/2;
    t[lc]=Node(lz[v], m-l+1);
    t[rc]=Node(lz[v], r-m);
    lz[lc]=lz[v];
    lz[rc]=lz[v];
    lz[v]=0;
}

void bld(int a[], int v=1, int l=1, int r=n) {
    if(l==r) t[v]=Node(a[l], 1);
    else {
        int m=(l+r)/2;
        bld(a, v*2, l, m);
        bld(a, v*2+1, m+1, r);
        t[v]=t[v*2]+t[v*2+1];
    }
}

void upd(int ql, int qr, int val, int v=1, int l=1, int r=n) {
    if(ql>r||qr<l) return;
    if(ql<=l&&qr>=r) {
        t[v]=Node(val, r-l+1);
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

Node get(int ql, int qr, int v=1, int l=1, int r=n) {
    if(ql>r||qr<l) return Node();
    if(ql<=l&&qr>=r) return t[v];
    else {
        push(v, l, r);
        int m=(l+r)/2;
        return get(ql, qr, v*2, l, m)+get(ql, qr, v*2+1, m+1, r);
    }
}

int qry(int i, int l, int r) {
    return p[i].order_of_key(r+1)-p[i].order_of_key(l);
}

int32_t main() {
    fastio;
    int q; cin>>n>>q;
    rep1(i, n) cin>>a[i];
    rep1(i, n) p[a[i]].insert(i);
    bld(a);
    rep(c, q) {
        int l, r, d; cin>>l>>r>>d;
        auto t=get(l, r);
        int ans=INT_MAX;
        rep(i, t.sz) {
            int v=t.lst[i].se;
            if(qry(v, l, r)>=(r-l+d+1)/d) ans=min(ans, v);
        }
        cout<<(ans==INT_MAX?-1:ans)<<endl;
    }
}