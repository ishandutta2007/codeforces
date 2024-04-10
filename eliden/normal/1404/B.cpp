#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin>>tests;
    rep(test,0,tests) {
        int n,a,b,da,db;
        cin>>n>>a>>b>>da>>db;
        --a;--b;
        vector<vector<int>> g(n);
        rep(i,0,n-1) {
            int x,y;
            cin>>x>>y;
            --x;--y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vector<int> dist(n), dep(n,1);
        int diam = 0;
        function<void(int,int)> dfs = [&](int u, int p) {
            for(int v:g[u]) {
                if(v==p) continue;
                dist[v] = dist[u]+1;
                dfs(v,u);
                diam=max(diam,dep[u]+dep[v]);
                dep[u]=max(dep[u],dep[v]+1);
            }
            diam=max(diam,dep[u]);
        };
        dfs(a,-1);
        // debug(dist[b]);
        // debug(diam);
        if(2*da>=db || dist[b]<=da || diam<=2*da+1) cout<<"Alice\n";
        else cout<<"Bob\n";
    }
}