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
const int M=10006;
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
    return (1LL*((1LL*f[n]*inv[r])%hell)*inv[n-r])%hell;
}
int ff(int n,int s,int u){
    if(n==0) return s==0;
    if(s<0 or u<0) return 0;
    int ans=0;
    rep(r,0,n+1){
        int k=s-(u+1)*r;
        if(k<0) break;
        if(r%2){
            ans=(ans-C(n,r)*C(n+k-1,k)%hell+hell)%hell;
        }
        else{
            ans=(ans+C(n,r)*C(n+k-1,k)%hell+hell)%hell;
        }
    }
    return ans;
}
int inverse[1001];
void solve(){
    compute();
    rep(i,1,1001) inverse[i]=expo(i,hell-2,hell);
    int p,s,r,ans=0,den=0;
    cin>>p>>s>>r;
    rep(i,r,s+1){
        rep(j,1,p+1){
            ans=(ans+C(p-1,j-1)*ff(p-j,s-j*i,i-1)%hell*inverse[j]%hell)%hell;
        }
        den=(den+ff(p-1,s-i,s))%hell;
    }
    ans=ans*expo(den,hell-2,hell)%hell;
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