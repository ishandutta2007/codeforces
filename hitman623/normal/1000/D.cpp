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
const int M=1006;
int f[M],inv[M];
int expo(int base,int exponent,int mod){
    int ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
void compute(){
    f[0]=1;
    rep(i,1,M){
        f[i]=(1LL*i*f[i-1])%hell;
    }
    inv[M-1]=expo(f[M-1],hell-2,hell);
    for(int i=M-2;i>=0;i--){
        inv[i]=(1LL*(i+1)*inv[i+1])%hell;
    }
}
int C(int n,int r){
    if(n<0 || r<0 || n<r) return 0;
    return (1LL*((1LL*f[n]*inv[r])%hell)*inv[n-r])%hell;
}
int n,dp[1005],ans,a[1005];
void solve(){
    compute();
    cin>>n;
    rep(i,0,n){
        cin>>a[i];
    }
    dp[n]=1;
    for(int i=n-1;i>=0;i--){
        if(a[i]>0 and a[i]<n-i){
            rep(j,i+1,n+1){
                dp[i]=(dp[i]+C(j-i-1,a[i])*dp[j])%hell;
            }
        }
        ans+=dp[i];
        ans%=hell;
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