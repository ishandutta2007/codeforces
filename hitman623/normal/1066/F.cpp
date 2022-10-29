#include <bits/stdc++.h>

#define int         long long
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
int n,dp[200005][2];
map<int,vii> v;
vii a[200005];
int dis(pii w,pii r){
    return abs(w.x-r.x)+abs(w.y-r.y);
}
int sol(int x,int d){
    if(x==sz(v)-1) return 0;
    if(dp[x][d]!=-1) return dp[x][d];
    int ans=1e16;
    if(d==0){
        ans=min(ans,sol(x+1,0)+dis(a[x][0],a[x+1].back())+dis(a[x+1][0],a[x+1].back()));
        ans=min(ans,sol(x+1,1)+dis(a[x][0],a[x+1][0])+dis(a[x+1][0],a[x+1].back()));
    }
    else{
        ans=min(ans,sol(x+1,0)+dis(a[x].back(),a[x+1].back())+dis(a[x+1][0],a[x+1].back()));
        ans=min(ans,sol(x+1,1)+dis(a[x].back(),a[x+1][0])+dis(a[x+1][0],a[x+1].back()));
    }
    return dp[x][d]=ans;
}
void solve(){
    cin>>n;
    rep(i,0,n){
        int x,y;
        cin>>x>>y;
        v[max({x,y})].pb({x,-y});
    }
    v[0].pb({0,0});
    for(auto &i: v) sort(all(i.y));
    int in=0;
    for(auto i:v){
        a[in]=i.y;
        for(auto &j:a[in]) j.y*=-1;
        in++;
    }
    memset(dp,-1,sizeof dp);
    cout<<sol(0,0)<<endl;
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