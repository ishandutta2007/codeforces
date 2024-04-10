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
#define rep(i, n) for (short i=0; i<(n); i++)
#define irep(i, n) for(int i=0; i<(n); i++)
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

map<pii, int> q;
int queries=0;
int ask(int i, int j) {
    if(i>j) swap(i, j);
    if(q.find({i, j})!=q.end()) return q[{i, j}];
    queries++; assert(queries<4270);
    cout<<"? "<<i+1<<' '<<j+1<<endl;
    int x; cin>>x; return q[{i, j}]=x;
}

int32_t main() {
    int n; cin>>n;
    vi ans(n, -1);
    int idx[n]; iota(idx, idx+n, 0); shuffle(idx, idx+n, rng);
    int x=idx[0], y=idx[1], sx=1, sy=1, z=ask(x, y);
    for(int j=2; j<n; j++) {
        //trying some weird query optimizations
        int i=idx[j], add=ceil(sqrt(i)/2);
        int tmp=ask(y, i);
        if(tmp>z) sx+=add, sy+=add;
        else if(tmp<z) z=tmp, x=i, sx=1, sy+=add;
        else y=i, z=ask(x, i), sx+=add, sy=1;
        if(rng()%(sx+sy)<sx) swap(sx, sy), swap(x, y);
    }
    int id=-1;
    while(1) {
        int c=rng()%n; while(c==x||c==y) c=rng()%n;
        int ax=ask(x, c), ay=ask(y, c);
        if(ax<ay) {id=x; break;}
        if(ay<ax) {id=y; break;}
    }
    ans[id]=0;
    rep(i, n) if(ans[i]==-1) ans[i]=ask(i, id);
    cout<<"! "; rep(i, n) cout<<ans[i]<<' '; cout<<endl;
    return 0;
}