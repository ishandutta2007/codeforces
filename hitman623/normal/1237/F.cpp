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
    if(n<r or n<0 or r<0) return 0;
    return (1LL*((1LL*f[n]*inv[r])%hell)*inv[n-r])%hell;
}
int h,w,n,r[3601],c[3601],ans,rows,cols;
int dpr[3603][3603];
int dpc[3603][3603];
void solve(){
    compute();
    cin>>h>>w>>n;
    rep(i,0,n){
        int a,b;
        cin>>a>>b;
        r[a]=c[b]=1;
        cin>>a>>b;
        r[a]=c[b]=1;
    }
    rep(i,1,h+1) if(!r[i]) rows++;
    rep(i,1,w+1) if(!c[i]) cols++;
    dpr[0][0]=1;
    rep(i,1,h+1){
        rep(j,0,h+1){
            dpr[i][j]=dpr[i-1][j];
            if(i-1>=1 and !r[i] and !r[i-1]) dpr[i][j]=(dpr[i][j]+dpr[i-2][j-1])%hell;
        }
    }
    dpc[0][0]=1;
    rep(i,1,w+1){
        rep(j,0,w+1){
            dpc[i][j]=dpc[i-1][j];
            if(i-1>=1 and !c[i] and !c[i-1]) dpc[i][j]=(dpc[i][j]+dpc[i-2][j-1])%hell;
        }
    }
    rep(t,0,h+1){
        rep(o,0,h+1){
            ans=(ans+dpr[h][t]*C(rows-2*t,o)%hell*dpc[w][o]%hell*C(cols-2*o,t)%hell*f[t]%hell*f[o]%hell)%hell;
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