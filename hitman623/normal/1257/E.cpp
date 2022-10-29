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
int n,k[3],a[3][200005],f[200005],g[200005],h[200005],d[200005];
void solve(){
    rep(i,0,3){
        cin>>k[i];
        n+=k[i];
    }
    rep(i,0,3){
        rep(j,0,k[i]){
            cin>>a[i][j];
        }
        sort(a[i],a[i]+k[i]);
    }
    rep(i,0,k[0]) f[a[0][i]]=g[a[0][i]]=1;
    rep(i,0,k[1]) d[a[1][i]]=1;
    for(int i=n;i>=0;i--) d[i]+=d[i+1];
    rep(i,1,n+2) f[i]+=f[i-1];
    rep(i,1,n+2) f[i]=i-f[i];
    for(int i=n;i>=0;i--) g[i]+=g[i+1];
    rep(i,0,k[2]) h[a[2][i]]=1;
    rep(i,1,n+2) h[i]+=h[i-1];
    rep(i,0,n+2) f[i]=f[i]-h[i]+g[i+1];
    rep(i,1,n+2) d[i]+=h[i-1];
    for(int i=n;i>=0;i--) d[i]=min(d[i],d[i+1]);
    int ans=hell;
    rep(i,0,n+1) ans=min(ans,f[i]+d[i+1]);
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