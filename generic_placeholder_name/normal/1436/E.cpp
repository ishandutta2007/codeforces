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

constexpr int N=1e5+5;
cc_hash_table<int, int> m[N];
vi Q[N];
int a[N];
vi p[N];

int t[4*N+4];
void upd(int pos, int val, int v=1, int l=1, int r=N) {
    if(l==r) t[v]=val;
    else {
        int m=(l+r)/2;
        if(pos<=m) upd(pos, val, v*2, l, m);
        else upd(pos, val, v*2+1, m+1, r);
        t[v]=min(t[v*2], t[v*2+1]);
    }
}

int bs(int val, int v=1, int l=1, int r=N) {
    if(l==r) return l;
    else {
        int m=(l+r)/2;
        if(t[v*2]<val) return bs(val, v*2, l, m);
        else return bs(val, v*2+1, m+1, r);
    }
}

#define sz(a) ((int)a.size())
int32_t main() {
    fastio;
    int n; cin>>n;
    rep(i, n) {
        cin>>a[i];
        p[a[i]].pb(i);
    }
    set<int> all{0};
    rep(i, n) all.insert(a[i]);
    int mex_all;
    for(int x: all) {
        if(all.find(x+1)==all.end()) {
            mex_all=x+1;
            break;
        }
    }
    rep1(i, n) {
        if(p[i].empty()) continue;
        if(p[i][0]-1>=0) Q[p[i][0]-1].eb(0);
        rep(j, sz(p[i])-1) if(p[i][j]+1<p[i][j+1]) Q[p[i][j+1]-1].eb(p[i][j]+1);
        if(p[i][sz(p[i])-1]+1<n) Q[n-1].eb(p[i][sz(p[i])-1]+1);
    }
    memset(t, -1, sizeof(t));
    rep(i, n) {
        upd(a[i], i);
        for(int l: Q[i]) m[l][i]=bs(l);
    }
    rep1(i, n+3) {
        bool ok=1;
        if(p[i].empty()) {
            ok&=(mex_all!=i);
        }
        else {
            if(p[i][0]-1>=0) ok&=(m[0][p[i][0]-1]!=i);
            rep(j, sz(p[i])-1) if(p[i][j]+1<p[i][j+1]) ok&=(m[p[i][j]+1][p[i][j+1]-1]!=i);
            if(p[i][sz(p[i])-1]+1<n) ok&=(m[p[i][sz(p[i])-1]+1][n-1]!=i);
        }
        if(ok) {
            cout<<i<<endl;
            return 0;
        }
    }
    assert(0);
}
#undef sz