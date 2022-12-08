#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<vi> g(n);
    rep(i,0,n-1) {
        int u,v;
        cin>>u>>v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> par(n,-1);
    vector<int> dp1(n), dp2(n);
    vector<bool> leaf(n);
    function<void(int,int)> dfs = [&](int u, int p) {
        vector<int> nxt;
        for(int v:g[u]) {
            if(v==p) continue;
            dfs(v,u);
            nxt.push_back(v);
        }
        if(sz(nxt)==0) {
            leaf[u]=true;
            return;
        }
        if(sz(nxt)==1) {
            dp1[u] = dp2[nxt[0]];
        }
        else {
            for(int v:nxt) dp1[u]+=dp2[v];
            dp1[u]+=sz(nxt)-1;
        }
        for(int v:nxt) {
            if(!leaf[v]) dp2[u]+=1+dp1[v];
        }
    };
    dfs(0,-1);
    cout<<min(dp1[0],dp2[0])<<"\n";
}