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
template<typename T, typename comp = less<T>>
using ordered_set = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int N=150005;
int n, m, p, s;

struct Node {
    vector<pii> lst; //(count, id)

    Node() {}
    Node(int id, int cnt) {lst.eb(cnt, id);}

    inline bool empty() const {return lst.empty();}
    inline void clear() {lst.clear();}

    friend Node operator + (const Node& a, const Node& b) { //O(n^2) since n is small
        Node c;
        c.lst=a.lst;
        for(auto x: b.lst) {
            bool ok=0;
            for(pii& y: c.lst) if(y.se==x.se) {
                y.fi+=x.fi;
                ok=1;
                break;
            }
            if(!ok) c.lst.pb(x);
        }
        sort(all(c.lst), greater<pii>());
        while(c.lst.size()>s) {
            int v=c.lst.back().fi; 
            for(auto& x: c.lst) x.fi-=v;
            c.lst.pop_back();
        }
        return c;
    }

    void operator = (const Node& oth) {
        lst=oth.lst;
    }

    inline void print() {
        cout<<lst.size()<<' ';
        for(auto& x: lst) cout<<x.se<<' ';
        cout<<endl;
    }
};

Node t[4*N+4];
int lz[4*N+4];
int a[N];

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

int32_t main() {
    fastio;
    cin>>n>>m>>p; s=100/p;
    rep1(i, n) cin>>a[i];
    bld(a);
    rep1(i, m) {
        int t; cin>>t;
        if(t==1) {
            int l, r, id; cin>>l>>r>>id;
            upd(l, r, id);
        }
        else {
            assert(t==2);
            int l, r; cin>>l>>r;
            auto res=get(l, r);
            res.print();
        }
    }
}