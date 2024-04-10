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
#define div         ddd
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int expo(int base,int exponent,int mod){
    int ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
vi div[100005];
void process_seive(){
    int n=100000;
    rep(i,1,n+1){
        for(int j=i;j<=n;j+=i){
            div[j].pb(i);
        }
    }
}
int m,f[100005],cnts[100005];
void solve(){
    process_seive();
    int ans=0;
    cin>>m;
    f[1]=0;
    rep(i,2,m+1){
        for(int j=sz(div[i])-1;j>=0;j--){
            cnts[j]=m/div[i][j];
            rep(k,j+1,sz(div[i])){
                if(div[i][k]%div[i][j]==0) cnts[j]-=cnts[k];
            }
        }
        int mbyx=m/i;
        rep(j,0,sz(div[i])-1){
            f[i]=(f[i]+cnts[j]*(f[div[i][j]]+1))%hell;
        }
        f[i]=(f[i]+mbyx)*expo((m+hell-mbyx)%hell,hell-2,hell)%hell;
    }
    rep(i,1,m+1) ans=(ans+f[i]+1)%hell;
    cout<<ans*expo(m,hell-2,hell)%hell<<endl;
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