#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma,popcnt")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

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
using ordered_set = tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int N=1e5+5;
struct Item {
    int val, cnt;

    Item() {}
    Item(int val, int cnt): val(val), cnt(cnt) {}
    int get() {return val*cnt;}
};

vector<Item> items;
bitset<N> vis;
vi v[N];
vi deps[N]; //depths with size == i
int cnt[N]; //count of depth size == i
int par[N];
vi adj[N];
int dep[N];
Item prv[N]; //knapsack traceback
bitset<N> ans;

int32_t main() {
    fastio;
    int n, k; cin>>n>>k;
    rep1(i, n-1) {
        int p; cin>>p;
        par[i]=--p;
        adj[p].pb(i);
    }
    queue<int> q; q.push(0);
    while(!q.empty()) {
        int u=q.front(); q.pop();
        v[dep[u]].pb(u);
        for(int to: adj[u]) {
            dep[to]=dep[u]+1;
            q.push(to);
        }
    }
    rep(i, n) if(!v[i].empty()) {
        deps[v[i].size()].pb(i);
        cnt[v[i].size()]++;
    }
    if(k==n||k==0) {
        cout<<*max_element(dep, dep+n)+1<<endl;
        rep(i, n) cout<<(k?'a':'b'); cout<<endl;
        return 0;
    }
    rep1(i, n) if(cnt[i]) {
        int m=cnt[i];
        for(int p=1; p<m; m-=p, p<<=1) items.eb(i, p);
        items.eb(i, m);
    }
    vis[0]=1;
    for(auto& item: items) {
        auto nxt=vis|(vis<<item.get());
        auto cvr=nxt^vis;
        for(int i=cvr._Find_first(); i<n; i=cvr._Find_next(i)) prv[i]=item;
        vis=nxt;
    }
    if(vis[k]) { //can knapsack
        cout<<*max_element(dep, dep+n)+1<<endl;
        int cur=k;
        while(cur) {
            rep(_, prv[cur].cnt) {
                int& c=prv[cur].val;
                int d=deps[c].back(); deps[c].pop_back();
                for(auto& x: v[d]) ans[x]=1;
            }
            cur-=prv[cur].get();
        }
        rep(i, n) cout<<(ans[i]?'a':'b'); cout<<endl;
    }
    else { //cannot knapsack, do greedy
        cout<<*max_element(dep, dep+n)+2<<endl;
        for(int i=0, m=n; m; m-=v[i++].size()) {
            if(v[i].size()<=k) {
                k-=v[i].size();
                for(int x: v[i]) ans[x]=1;
            }
            else if(v[i].size()<=m-k) {} //everything in default state
            else {
                bool p=k<m-k;
                int c=min(k, m-k);
                k-=p*c;
                vi leaves;
                for(int x: v[i]) if(adj[x].empty()) leaves.pb(x);
                rep(i, c) ans[leaves.back()]=p, leaves.pop_back();
                for(int x: leaves) ans[x]=!p;
                for(int x: v[i]) if(!adj[x].empty()) ans[x]=!p;
            }
        }
        rep(i, n) cout<<(ans[i]?'a':'b'); cout<<endl;
    }
}