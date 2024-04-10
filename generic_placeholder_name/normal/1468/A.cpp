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
template<typename T, typename cmp = less<T>>
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

class SegTree {
    int n;
    vi t;

    void upd(int pos, int val, int v, int l, int r) {
        if(l==r) t[v]=val;
        else {
            int m=(l+r)/2;
            if(pos<=m) upd(pos, val, v*2, l, m);
            else upd(pos, val, v*2+1, m+1, r);
            t[v]=max(t[v*2], t[v*2+1]);
        }
    }

    int get(int ql, int qr, int v, int l, int r) {
        if(ql>r||qr<l) return INT_MIN;
        if(ql<=l&&qr>=r) return t[v];
        else {
            int m=(l+r)/2;
            return max(get(ql, qr, v*2, l, m), get(ql, qr, v*2+1, m+1, r));
        }
    }

public:
    SegTree(int n): n(n), t(4*n+4, 0) {}
    void upd(int pos, int val) {upd(pos, val, 1, 0, n-1);}
    int get(int ql, int qr) {return get(ql, qr, 1, 0, n-1);}
};

void solve_case() {
    int n; cin>>n;
    vi a(n); rep(i, n) cin>>a[i];
    vi p(n); iota(all(p), 0);
    sort(all(p), [&a](int x, int y) {return mp(a[x], x)<mp(a[y], y);});
    SegTree t(n);
    set<int, greater<int>> s;
    rep(i, n) s.insert(i);
    for(int i: p) {
        s.erase(i);
        int ans=1;
        auto nxt=s.upper_bound(i);
        if(nxt!=s.end()) ans=max(ans, max(0, t.get(0, *nxt-1))+2);
        ans=max(ans, t.get(0, i-1)+1);
        t.upd(i, ans);
    }
    cout<<t.get(0, n-1)<<endl;
}

int32_t main() {
    fastio;
    int T; cin>>T;
    while(T--) solve_case();
}