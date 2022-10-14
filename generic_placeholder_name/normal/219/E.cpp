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

int n;
int len(const pii& a) {
    return a.fi==1 ? a.se-1
            : a.se>n ? a.se-a.fi
            : (a.se-a.fi+1)/2;
}

bool comp_seg(const pii& a, const pii& b) {
    return mp(-len(a), a.fi)<mp(-len(b), b.fi);
}

int32_t main() {
    //implementation 100
    //really just
    //fucking obvious + annoying side cases
    //also did i mention the horribleness that is C++'s std syntax?
    fastio;
    set<pii, decltype(comp_seg)*> segs(comp_seg);
    unordered_map<int, int> nxt, prev, pos;
    //data structures
    int q; cin>>n>>q;
    segs.insert({1, n+1});
    nxt[0]=n; prev[n+1]=0;
    const auto getm=[&](const pii& a) -> int {
        return a.fi==1 ? 1
                : a.se>n ? n
                : (a.se+a.fi-1)/2;
    };
    while(q--) {
        int t, idx; cin>>t>>idx;
        if(t==1) {
            int l=segs.begin()->fi, r=segs.begin()->se; segs.erase(segs.begin());
            int m=getm({l, r}); pos[idx]=m;
            segs.insert({l, m});
            segs.insert({m+1, r});
            prev[m]=l-1; nxt[l-1]=m;
            prev[r]=m; nxt[m]=r;
            cout<<m<<endl;
        }
        else {
            int x=pos[idx], l=prev[x], r=nxt[x];
            segs.erase({l+1, x});
            segs.erase({x+1, r});
            segs.insert({l+1, r});
            prev[r]=l; nxt[l]=r;
        }
    }
}