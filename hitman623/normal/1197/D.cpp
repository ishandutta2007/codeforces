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
int n,m,k,f[10],p[300005],ans=-1e17,a[300005];
void solve(){
    cin>>n>>m>>k;
    rep(i,0,n) cin>>a[i];
    p[0]=a[0];
    rep(i,1,n) p[i]=a[i]+p[i-1];
    rep(x,0,m){
        rep(i,0,m) f[i]=0;
        for(int i=n-1;i>=0;i--){
            if(i+m-1<n) f[i%m]=max(0LL,p[i+m-1]-(i?p[i-1]:0)-k+max(0LL,f[i%m]));
            if(i+x-1<n) ans=max(ans,p[i+x-1]-(i?p[i-1]:0)-(x?k:0)+f[(i+x)%m]);
        }
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