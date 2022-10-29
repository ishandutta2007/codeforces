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
int n,dp[202][202][202],m,p[202];
string s;
void pre(){
    p[0]=0;
    rep(i,1,m){
        string g=s;
        g[i]='('+')'-s[i];
        rep(j,1,i+1){
            int f=1;
            rep(k,0,j){
                if(s[k]!=g[i-j+k+1]) f=0;
            }
            if(f) p[i]=j;
        }
    }
}
int sol(int in,int c,int bal){
    if(in==n) return c!=m and bal==0;
    if(c==m || bal<0) return 0;
    if(dp[in][c][bal]!=-1) return dp[in][c][bal];
    int ans=0;
    if(s[c]=='(') ans=ans+sol(in+1,c+1,bal+1);
    else ans=ans+sol(in+1,c+1,bal-1);
    if(s[c]=='(') ans=ans+sol(in+1,p[c],bal-1);
    else ans=ans+sol(in+1,p[c],bal+1);
    ans%=hell;
    return dp[in][c][bal]=ans;
}
int expo(int base,int exponent,int mod){
    int ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
void solve(){
    cin>>n>>s;
    memset(dp,-1,sizeof dp);
    n*=2;
    m=sz(s);
    pre();
    int ans=1;
    rep(i,1,n+1){
        ans=(ans*i)%hell;
    }
    rep(i,1,n/2+1){
        ans=(ans*expo(i,hell-2,hell))%hell;
    }
    rep(i,1,n/2+2){
        ans=(ans*expo(i,hell-2,hell))%hell;
    }
    ans=(ans-sol(0,0,0)+hell)%hell;
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