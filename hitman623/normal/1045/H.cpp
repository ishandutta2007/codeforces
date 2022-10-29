#include <bits/stdc++.h>

#define int         long long
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
const int M=1000006;
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
    rep(i,1,M) f[i]=(1LL*i*f[i-1])%hell;
    inv[M-1]=expo(f[M-1],hell-2,hell);
    for(int i=M-2;i>=0;i--) inv[i]=(1LL*(i+1)*inv[i+1])%hell;
}
int C(int n,int r){
    if(n==-1 and r==0) return 1;
    return (1LL*((1LL*f[n]*inv[r])%hell)*inv[n-r])%hell;
}
int g(int c00,int c01,int c10,int c11,int last){
    if(last==0){
        if(c01==c10+1) return C(c01+c00-1,c00)*C(c01+c11-1,c11)%hell;
        else if(c10==c01) return C(c01+c00,c00)*C(c01+c11-1,c11)%hell;
        else return 0;
    }
    else{
        if(c10==c01+1) return C(c10+c00-1,c00)*C(c10+c11-1,c11)%hell;
        else if(c01==c10) return C(c01+c00-1,c00)*C(c01+c11,c11)%hell;
        else return 0;
    }
}
string a,b;
int n;
int sol(int in,int c00,int c01,int c10,int c11,int fa,int fb,int last){
    if(c00<0 or c01<0 or c10<0 or c11<0) return 0;
    if(in==n) return c00==0 and c01==0 and c10==0 and c11==0;
    if(fa and fb) return g(c00,c01,c10,c11,last);
    else if(fa){
        if(b[in]=='0') return sol(in+1,c00-(last==0),c01,c10-(last==1),c11,1,0,0);
        else return (sol(in+1,c00-(last==0),c01,c10-(last==1),c11,1,1,0)+sol(in+1,c00,c01-(last==0),c10,c11-(last==1),1,0,1))%hell;
    }
    else if(fb){
        if(a[in]=='1') return sol(in+1,c00,c01-(last==0),c10,c11-(last==1),0,1,1);
        else return (sol(in+1,c00-(last==0),c01,c10-(last==1),c11,0,1,0)+sol(in+1,c00,c01-(last==0),c10,c11-(last==1),1,1,1))%hell;        
    }
    else{
        if(a[in]==b[in]){
            if(a[in]=='0') return sol(in+1,c00-(last==0),c01,c10-(last==1),c11,0,0,0);
            else return sol(in+1,c00,c01-(last==0),c10,c11-(last==1),0,0,1);
        }
        else return (sol(in+1,c00-(last==0),c01,c10-(last==1),c11,0,1,0)+sol(in+1,c00,c01-(last==0),c10,c11-(last==1),1,0,1))%hell;        
    }
}
int c00,c01,c10,c11;
void solve(){
    compute();
    cin>>a>>b>>c00>>c01>>c10>>c11;
    n=c00+c01+c10+c11+1;
    if(n>sz(b) || n<sz(a) || (c10-c01!=1 and c10!=c01)){
        cout<<0<<endl;
        return;
    }
    cout<<sol(1,c00,c01,c10,c11,n>sz(a),n<sz(b),1)<<endl;
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