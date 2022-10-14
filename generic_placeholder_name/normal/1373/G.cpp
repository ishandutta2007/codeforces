#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma,popcnt")

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

constexpr int N=6e5+10;
int t[4*N+8], lz[4*N+8];

void push(int v) {
    if(!lz[v]) return;
    int lc=v*2, rc=v*2+1;
    t[lc]+=lz[v];
    t[rc]+=lz[v];
    lz[lc]+=lz[v];
    lz[rc]+=lz[v];
    lz[v]=0;
}

void upd(int ql, int qr, int val, int v=1, int l=0, int r=N) {
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

int get(int ql, int qr, int v=1, int l=0, int r=N) {
    if(ql>r||qr<l) return 0;
    if(ql<=l&&qr>=r) return t[v];
    else {
        push(v);
        int m=(l+r)/2;
        return min(get(ql, qr, v*2, l, m), get(ql, qr, v*2+1, m+1, r));
    }
}

int32_t main() {
    fastio;
    int n, k, q; cin>>n>>k>>q;
    set<pii> s;
    multiset<int, greater<int>> ms;
    for(int i=0; i<=N; i++) upd(i, i, -i+1);
    while(q--) {
        int x, y; cin>>x>>y;
        y+=abs(k-x);
        int amt;
        if(s.find({x, y})==s.end()) {
            s.emplace(x, y);
            amt=-1;
            ms.insert(y);
        }
        else {
            s.erase({x, y});
            amt=1;
            ms.erase(ms.find(y));
        }
        upd(0, y, amt);
        int l=*ms.begin(), r=N;
        int lst=0;
        while(l<r) {
            int m=(l+r)/2;
            upd(0, N, m-lst);
            lst=m;
            if(get(0, m)>=0) r=m;
            else l=m+1;
        }
        upd(0, N, -lst);
        cout<<max(l-n, 0)<<endl;
    }
}