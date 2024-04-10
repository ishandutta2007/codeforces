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

struct Node {
    typedef shared_ptr<Node> NodePtr;
    NodePtr l, r;
    int v;

    Node(): l(nullptr), r(nullptr), v(0) {}
    Node(int v): l(nullptr), r(nullptr), v(v) {}
    Node(NodePtr _l, NodePtr _r): l(_l), r(_r), v(0) {}
    Node(NodePtr _l, NodePtr _r, int v): l(_l), r(_r), v(v) {}
};

typedef shared_ptr<Node> NodePtr;
constexpr int N=35005;
constexpr int K=55;

NodePtr t[N];
int dp[K][N];
int a[N];
int k, n;

NodePtr bld(int l=1, int r=n) {
    if(l==r) return make_shared<Node>();
    else {
        int m=(l+r)/2;
        return make_shared<Node>(move(bld(l, m)), move(bld(m+1, r)));
    }
}

NodePtr upd(NodePtr& rt, int pos, int val, int l=1, int r=n) {
    if(l==r) return make_shared<Node>(val);
    else {
        int m=(l+r)/2;
        if(pos<=m) {
            NodePtr nl=move(upd(rt->l, pos, val, l, m));
            return make_shared<Node>(move(nl), rt->r, nl->v+rt->r->v);
        }
        else {
            NodePtr nr=move(upd(rt->r, pos, val, m+1, r));
            return make_shared<Node>(rt->l, move(nr), rt->l->v+nr->v);
        }
    }
}

int get(NodePtr& rt, int ql, int qr, int l=1, int r=n) {
    if(!rt||ql>r||qr<l) return 0;
    if(ql<=l&&qr>=r) return rt->v;
    else {
        int m=(l+r)/2;
        return get(rt->l, ql, qr, l, m)+get(rt->r, ql, qr, m+1, r);
    }
}

unordered_map<int, int> lst;
unordered_map<int, int> mem[N];

inline int cost(int l, int r) {
    if(mem[r].find(l)!=mem[r].end()) return mem[r][l];
    else return mem[r][l]=get(t[r], l+1, r);
}

void calc(int cur, int l, int r, int optl, int optr) {
    if(l>r) return;
    int prv=cur-1;
    int mx=0, lf=-1, rg=-1;
    int m=(l+r)/2;
    for(int k=optl; k<=min(m-1, optr); k++) {
        int cst=cost(k, m);
        if(mx<dp[prv][k]+cst) {
            mx=dp[prv][k]+cst;
            lf=rg=k;
        }
        else if(mx==dp[prv][k]+cst) rg=k;
    }
    assert(~lf);
    dp[cur][m]=mx;
    calc(cur, l, m-1, optl, lf);
    calc(cur, m+1, r, rg, optr);
}

int32_t main() {
    fastio;
    cin>>n>>k;
    rep1(i, n) cin>>a[i];
    t[0]=move(bld());
    rep1(i, n) {
        if(lst.find(a[i])==lst.end()) t[i]=t[i-1];
        else t[i]=move(upd(t[i-1], lst[a[i]], 0));
        t[i]=move(upd(t[i], i, 1));
        lst[a[i]]=i;
    }
    rep1(i, n) dp[1][i]=get(t[i], 1, i);
    for(int i=2; i<=k; i++) calc(i, i, n, i-1, n);
    cout<<dp[k][n]<<endl;
}