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
#define hell        998244353
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,k,m,l[500005],r[500005],x[500005],p[500005],v[500005],dp[500005],predp[500005];
void solve(){
    int ans=1;
    cin>>n>>k>>m;
    rep(i,0,m) cin>>l[i]>>r[i]>>x[i];
    rep(bit,0,k){
        rep(i,1,n+1){
            p[i]=0;
            v[i]=0;
        }
        rep(i,0,m){
            if((x[i]>>bit)&1) p[l[i]]++,p[r[i]+1]--;
            else v[r[i]]=max(v[r[i]],l[i]);
        }
        rep(i,1,n+1) p[i]+=p[i-1];
        rep(i,1,n+1) p[i]=p[i]>0;
        rep(i,1,n+1) dp[i]=predp[i]=0;
        dp[0]=1;
        predp[0]=(p[1]==0);
        int cur=0;
        rep(i,1,n+1){
            if(v[i]<=cur) dp[i]=dp[i-1]*(1+!p[i])%hell;
            else{
                cur=v[i];
                // dp[cur-1]+dp[cur]+dp[i-1]
                dp[i]=(predp[i-1]-(cur>=2?predp[cur-2]:0)+hell)%hell;
            }
            predp[i]=(predp[i-1]+(p[i+1]==0?dp[i]:0))%hell;
        }
        ans=(ans*dp[n])%hell;
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