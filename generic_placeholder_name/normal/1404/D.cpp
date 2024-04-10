#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma 03

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

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n; cin>>n;
    if(n%2) {
        cout<<"Second\n";
        vi adj[2*n+1];
        int prv[n+1]={0};
        rep1(i, 2*n) {
            int x; cin>>x;
            if(!prv[x]) prv[x]=i;
            else {
                int v=prv[x];
                adj[i].pb(v);
                adj[v].pb(i);
            }
        }
        rep1(i, n) adj[i].pb(i+n), adj[i+n].pb(i);
        vb vis(2*n+1, 0);
        vi a[2];
        function<void(int, int)> dfs = [&](int u, int c) {
            a[c].pb(u); vis[u]=1;
            for(int v: adj[u]) if(!vis[v]) dfs(v, c^1);
        };
        rep1(i, 2*n) if(!vis[i]) dfs(i, 0);
        if(accumulate(all(a[0]), 0LL)%(2*n)) swap(a[0], a[1]);
        for(int it: a[0]) cout<<it<<' '; cout<<endl;
    }
    else {
        cout<<"First\n";
        rep(i, 2*n) cout<<i%n+1<<' '; cout<<endl;
    }
    int ret; cin>>ret; assert(ret==0);
}