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
template<typename _def> using ordered_set=tree<_def, null_type, greater<_def>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

struct Trie {
    struct Node {
        vi v;
        Node* c[2];

        Node() {c[0]=c[1]=nullptr;}
    };
    Node* rt;

    void insert(Node* cur, int x, int8_t dep) {
        cur->v.pb(x);
        if(dep<0) return;
        int dir=(x>>dep)&1;
        if(!cur->c[dir]) cur->c[dir]=new Node();
        insert(cur->c[dir], x, dep-1);
    }
    inline void insert(int x) {insert(rt, x, 29);}

    int min_xor(Node* cur, int x, int8_t dep) const {
        if(dep<0) return 0;
        int8_t dir=(x>>dep)&1;
        if(cur->c[dir]) return min_xor(cur->c[dir], x, dep-1);
        else return (1<<dep)+min_xor(cur->c[!dir], x, dep-1);
    }

    ll get_mst(Node* cur, int8_t dep) const {
        if(dep<0) return 0;
        if(!cur->c[0]) return get_mst(cur->c[1], dep-1);
        if(!cur->c[1]) return get_mst(cur->c[0], dep-1);
        ll ans=get_mst(cur->c[0], dep-1)+get_mst(cur->c[1], dep-1);
        int mn=INT_MAX;
        for(int x: cur->c[0]->v) mn=min(mn, (1<<dep)+min_xor(cur->c[1], x, dep-1));
        return ans+mn;
    }
    inline ll get_mst() const {return get_mst(rt, 29);}

    void delete_node(Node* rt) {
        if(!rt) return;
        delete_node(rt->c[0]);
        delete_node(rt->c[1]);
        delete rt;
    }

    Trie() {}
    Trie(vi& a) {rt=new Node(); for(int x: a) insert(x);}

    ~Trie() {delete_node(rt);}
};

int32_t main() {
    fastio;
    int n; cin>>n;
    vi a(n); rep(i, n) cin>>a[i];
    const Trie t(a);
    cout<<t.get_mst()<<endl;
}