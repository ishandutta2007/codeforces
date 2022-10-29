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
#define hell        1000000000000000007LL
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,g,r,x[10004],dp[10004][1001];
void solve(){
    cin>>n>>m;
    rep(i,0,m) cin>>x[i];
    sort(x,x+m);
    cin>>g>>r;
    memset(dp,-1,sizeof dp);
    deque<pair<int,pii>> pq;
    pq.push_front({0,{0,0}});
    while(!pq.empty()){
        auto d=pq.front();
        pq.pop_front();
        int pos=d.y.x,mod=d.y.y;
        if(dp[pos][mod]!=-1) continue;
        dp[pos][mod]=d.x;
        if(pos+1<m and mod+x[pos+1]-x[pos]<=g){
            int nm=mod+x[pos+1]-x[pos];
            if(nm<g and dp[pos+1][nm]==-1) pq.push_front({d.x,{pos+1,nm}});
            else if(nm==g and dp[pos+1][0]==-1) pq.push_back({d.x+1,{pos+1,0}});
        }
        if(pos-1>=0 and mod-x[pos-1]+x[pos]<=g){
            int nm=mod-x[pos-1]+x[pos];
            if(nm<g and dp[pos-1][nm]==-1) pq.push_front({d.x,{pos-1,nm}});
            else if(nm==g and dp[pos-1][0]==-1) pq.push_back({d.x+1,{pos-1,0}});
        }
    }
    ll ans=hell;
    rep(i,0,m){
        if(dp[i][0]!=-1 and n-x[i]<=g) ans=min(ans,1LL*(r+g)*dp[i][0]+n-x[i]);
    }
    if(ans<hell) cout<<ans<<endl;
    else cout<<-1<<endl;
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