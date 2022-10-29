#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,p[200005],ans,h[200005],mark[200005];
vi a[200005];
priority_queue<pii> pq;
void dfs(int node,int par){
    if(par==1) mark[node]=2;
    p[node]=par;
    h[node]=h[par]+1;
    for(auto i:a[node]){
        if(i!=par) dfs(i,node);
    }
}
void solve(){
    cin>>n;
    rep(i,0,n-1){
        int x,y;
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    dfs(1,1);
    rep(i,1,n+1) pq.push({h[i],i});
    while(!pq.empty()){
        auto d=pq.top();
        pq.pop();
        if(mark[d.y] or mark[p[d.y]]==2) continue;
        ans++;
        mark[p[d.y]]=2;
        mark[p[p[d.y]]]=max(1,mark[p[p[d.y]]]);
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}