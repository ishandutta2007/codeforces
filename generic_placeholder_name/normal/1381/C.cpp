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

void solve(vi& a, int x, int y) {
    int n=a.size();
    vvi ids(n+2);
    rep(i, n) ids[a[i]].pb(i);
    int excl=0; rep1(i, n+1) if(ids[i].empty()) {excl=i; break;}
    vi ans(n, -1);
    //choosing good points
    vi good;
    priority_queue<pii> pq;
    rep1(i, n+1) if(!ids[i].empty()) pq.emplace(ids[i].size(), i);
    rep(i, x) {
        int sz=pq.top().fi-1, id=pq.top().se; pq.pop();
        good.pb(ids[id].back());
        ids[id].pop_back(); if(sz!=0) pq.emplace(sz, id);
    }
    for(int it: good) ans[it]=a[it];
    //choosing misaligned points
    int add=pq.empty()?0:pq.top().fi;
    if(add*2-(n-y)>n-x) {cout<<"NO\n"; return;}
    vi rest;
    while(!pq.empty()) {
        int id=pq.top().se; pq.pop();
        for(int it: ids[id]) rest.pb(it);
    }
    rep(i, n-x) ans[rest[(i+add)%rest.size()]]=a[rest[i]];
    rep(i, n-y) ans[rest[i]]=excl;
    cout<<"YES\n";
    rep(i, n) cout<<ans[i]<<' '; cout<<endl;
}

int32_t main() {
    fastio;
    int q; cin>>q;
    while(q--) {
        int n, x, y; cin>>n>>x>>y;
        vi a(n); rep(i, n) cin>>a[i];
        solve(a, x, y);
    }
}