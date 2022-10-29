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
#define hell        998244353
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
string s,p;
int dp[3003][3003],pws[3003];
int go(int x,int y){
    if(y==sz(p)) return pws[sz(s)-x];
    if(x==sz(s)) return 0;
    int &ans=dp[x][y];
    if(ans!=-1) return ans;
    ans=go(x+1,y);
    if(p[y]==s[x]) ans=(ans+go(x+1,y+1))%hell;
    return ans;
}
int dp3[3003][3003];
int go3(int x,int y){
    if(y==0) return sz(s)-x+1;
    if(x==sz(s)) return 0;
    int &ans=dp3[x][y];
    if(ans!=-1) return ans;
    ans=go3(x+1,y);
    if(s[x]==p[y-1]) ans=(ans+go3(x+1,y-1))%hell;
    return ans;
}
int dp2[3003][3003];
int go2(int x,int y){
    if(y==0) return go3(sz(p)-x,x);
    int &ans=dp2[x][y];
    if(ans!=-1) return ans;
    ans=0;
    if(x and p[x-1]==s[sz(p)-x-y]) ans=(ans+go2(x-1,y))%hell;
    if(y and p[sz(p)-y]==s[sz(p)-x-y]) ans=(ans+go2(x,y-1))%hell;
    return ans;
}
void solve(){
    pws[0]=1;
    rep(i,1,3003) pws[i]=pws[i-1]*2%hell;
    cin>>s>>p;
    reverse(all(s));
    memset(dp,-1,sizeof dp);
    memset(dp2,-1,sizeof dp2);
    memset(dp3,-1,sizeof dp3);
    int ans=0;
    rep(i,0,sz(s)) ans=(ans+go(i,0))%hell;
    reverse(all(s));
    rep(i,1,sz(p)+1) ans=(ans+go2(sz(p)-i,i))%hell;
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