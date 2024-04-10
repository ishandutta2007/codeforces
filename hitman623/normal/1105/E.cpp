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
int n,adj[40],dp[1<<20];
int go(int mask){
    if(mask==0) return 0;
    if(mask<(1<<20) and dp[mask]!=-1) return dp[mask];
    int k=log2(mask);
    int ans=max(go(mask^(1LL<<k)),go((mask^(1LL<<k))&adj[k])+1);
    if(mask<(1<<20)) dp[mask]=ans;
    return ans;
}
int get_maximum_clique(){
    memset(dp,-1,sizeof dp);
    return go((1LL<<n)-1);
}
map<string,int> mp;
int vis[40],cur,q;
void solve(){
    cin>>q>>n;
    rep(i,0,q+1){
        int x=1;
        if(i!=q) cin>>x;
        if(x==1){
            rep(j,0,40){
                rep(k,j+1,40){
                    if(vis[j] and vis[k]){
                        adj[j]|=1LL<<k;
                        adj[k]|=1LL<<j;
                    }
                }
            }
            rep(j,0,40) vis[j]=0;
        }
        else{
            string s;
            int y;
            cin>>s;
            if(mp.count(s)==0) mp[s]=cur++;
            y=mp[s];
            vis[y]=1; 
        }
    }
    rep(i,0,n) adj[i]^=(1LL<<n)-1;
    cout<<get_maximum_clique()<<endl;
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