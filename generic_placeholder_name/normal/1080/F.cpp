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

constexpr int INF=1e9;
struct Node {
    int v;
    typedef shared_ptr<Node> NodePtr;
    NodePtr lc, rc;
    Node(): v(INF), lc(nullptr), rc(nullptr) {}
    Node(int v, NodePtr& lc, NodePtr& rc): v(v), lc(lc), rc(rc) {}
    void pull() {
        if(!lc||!rc) return;
        v=max(lc->v, rc->v);
    }
};

constexpr int N=1e5+5, K=3e5+5;
int n, m, k;
tuple<int, int, int> seg[K];
typedef shared_ptr<Node> NodePtr;
NodePtr t[K];

void bld(NodePtr& rt, int l=1, int r=n) {
    rt=make_shared<Node>();
    if(l!=r) {
        int m=(l+r)/2;
        bld(rt->lc, l, m);
        bld(rt->rc, m+1, r);
    }
}

NodePtr upd(const NodePtr& rt, int v, int i, int l=1, int r=n) {
    NodePtr nxt=make_shared<Node>(rt->v, rt->lc, rt->rc);
    if(l==r) {
        nxt->v=min(v, nxt->v);
        return nxt;
    }
    else {
        int m=(l+r)/2;
        if(i<=m) nxt->lc=upd(rt->lc, v, i, l, m);
        else nxt->rc=upd(rt->rc, v, i, m+1, r);
        nxt->pull();
        return nxt;
    }
}

int get(const NodePtr& rt, int ql, int qr, int l=1, int r=n) {
    if(ql>r||qr<l) return 0;
    if(ql<=l&&qr>=r) return rt->v;
    else {
        int m=(l+r)/2;
        return max(get(rt->lc, ql, qr, l, m), get(rt->rc, ql, qr, m+1, r));
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    rep(i, k) {
        int x, y, z; cin>>x>>y>>z;
        seg[i]=make_tuple(x, y, z);
    }
    sort(seg, seg+k);
    t[k]=make_shared<Node>();
    bld(t[k]);
    for(int i=k-1; ~i; i--) t[i]=upd(t[i+1], get<1>(seg[i]), get<2>(seg[i]));
    rep(i, m) {
        int a, b, x, y; cin>>a>>b>>x>>y;
        int p=lower_bound(seg, seg+k, make_tuple(x, 0, 0))-seg;
        if(p==k) cout<<"no\n";
        else cout<<(get(t[p], a, b)<=y?"yes\n":"no\n");
    }
}