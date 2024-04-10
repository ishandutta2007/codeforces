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
int n,s,m,k,a[2002],l[2002],r[2002],dp[1602][1602],c[2002],p[2002];
vi range[2002];
int sol(int pos,int rem){
    if(rem<=0) return 0;
    if(pos==n+1) return s+1;
    if(dp[pos][rem]!=-1) return dp[pos][rem];
    int &ans=dp[pos][rem];
    ans=sol(pos+1,rem);
    if(c[pos]>=pos) ans=min(ans,1+sol(c[pos]+1,rem-(p[c[pos]]-p[pos-1])));
    return ans;
}
bool check(int mid){
    rep(i,1,n+1){
        p[i]=(a[i]<=mid)+p[i-1];
    }
    memset(dp,-1,sizeof dp);
    return sol(1,k)<=m;
}
void solve(){
    cin>>n>>s>>m>>k;
    rep(i,1,n+1){
        cin>>a[i];
    }
    rep(i,1,s+1){
        cin>>l[i]>>r[i];
        range[l[i]].pb(r[i]);
    }
    int mx=0;
    rep(i,1,n+1){
        for(auto j:range[i]){
            mx=max(mx,j);
        }
        c[i]=mx;
    }
    int lo=0,hi=1e9+1;
    while(hi-lo>1){
        int mid=(lo+hi)/2;
        if(check(mid)) hi=mid;
        else lo=mid;
    }
    if(hi==1e9+1) cout<<-1<<endl;
    else cout<<hi<<endl;
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