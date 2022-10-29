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
#define blcksz      200
#define endl        '\n'
#define hell        998244353
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,k,v1[120005],v2[120005],a[120005];
vi pos[120005];
int cost[120005],lazy[1001],dp[120005],s[1001];
pii v[1001][blcksz+2];
inline int add(int x,int y){
    if(x+y>=hell) return x+y-hell;
    else return x+y;
}
void make(int b){
    s[b]=0;
    rep(i,max(1,b*blcksz),(b+1)*blcksz) v[b][s[b]++]={cost[i],dp[i-1]};
    sort(v[b],v[b]+s[b]);
    rep(i,1,s[b]) v[b][i].y=add(v[b][i].y,v[b][i-1].y);
}
void update(int l,int r,int x){
    if(l>r) return;
    int bl=l/blcksz;
    int br=r/blcksz;
    if(bl==br){
        rep(i,l,r+1) cost[i]+=x;
        make(bl);
    }
    else{
        rep(i,l,(bl+1)*blcksz) cost[i]+=x;
        make(bl);
        rep(i,br*blcksz,r+1) cost[i]+=x;
        make(br);
        rep(i,bl+1,br) lazy[i]+=x;
    }
}
int query(int x){
    int bx=x/blcksz;
    int ans=0;
    rep(i,0,bx){
        pii temp={k-lazy[i],hell};
        int l=upper_bound(v[i],v[i]+s[i],temp)-v[i]-1;
        if(l>=0) ans=add(ans,v[i][l].y);
    }
    rep(i,max(1,bx*blcksz),x+1){
        if(cost[i]+lazy[bx]<=k){
            ans=add(ans,dp[i-1]);
        }
    }
    return ans;
}
void solve(){
    cin>>n>>k;
    rep(i,1,n+1) cin>>a[i];
    rep(i,1,n+1){
        if(sz(pos[a[i]])) v1[i]=pos[a[i]].back();
        if(sz(pos[a[i]])>1) v2[i]=pos[a[i]][sz(pos[a[i]])-2];
        pos[a[i]].pb(i);
    }
    dp[0]=1;
    make(0);
    rep(i,1,n+1){
        update(v1[i]+1,i,1);
        update(v2[i]+1,v1[i],-1);
        dp[i]=query(i);
        make(i/blcksz);
    }
    cout<<dp[n]<<endl;
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