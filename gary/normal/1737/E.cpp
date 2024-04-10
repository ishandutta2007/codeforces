/**
 *    author:  gary
 *    created: 07.10.2022 22:15:21
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=1e6+20;
int dp[MAXN],suf[MAXN];
namespace combination
{
    const int MOD=1e9+7;
    int fact[MAXN+1],ifact[MAXN+1];
    int quick(int k1,int k2){
		int k3=1;for(;k2;k2>>=1,k1=1LL*k1*k1%MOD)if(k2&1)k3=1LL*k3*k1%MOD;return k3;
	}
    int inv(int A){return quick(A,MOD-2);}
    void genmath(){
        fact[0]=1;
        rb(i,1,MAXN) fact[i]=1ll*fact[i-1]*i%MOD;
        ifact[MAXN]=inv(fact[MAXN]);
        rl(i,MAXN-1,0) ifact[i]=1ll*ifact[i+1]*(i+1)%MOD;
    }
    int comb(int A,int B){
        if(A<0||B<0) return 0;
        if(A<B) return 0;
        return 1ll*fact[A]*ifact[B]%MOD*ifact[A-B]%MOD;
    }
    void add(int &A,int B){
        A+=B;
        if(A>=MOD) A-=MOD;
    }
    void sub(int &A,int B){
        A+=MOD-B;
        if(A>=MOD) A-=MOD;
    }
} // namespace combination
using namespace combination;
int ipw[MAXN];
void solve(){
    int n;
    cin>>n;
    if(n==1){
        cout<<1<<endl;
        return ;
    }
    suf[n+2]=0;
    dp[n+1]=suf[n+1]=1;
    rl(i,n,3){
        suf[i]=suf[i+1];
        dp[i]=suf[i+1];
        sub(dp[i],suf[min(n+2,2*i-1)]);
        add(suf[i],dp[i]);
    }
    rb(i,1,n){
        if(i==1){
            cout<<0<<"\n";
            continue;
        }
        int x=(i+1)/2;
        int y=ipw[x];
        // cout<<y<<endl;
        if(i!=n){
            y=1ll*y*dp[i+1]%MOD;
            y=1ll*y*ipw[n-i-1]%MOD;
        }
        else{
            y=2ll*y%MOD;
        }
        cout<<y<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    ipw[0]=1;
    ipw[1]=inv(2);
    rb(i,2,1000000) ipw[i]=1ll*ipw[1]*ipw[i-1]%MOD;
    while (t--)
    {
        solve();
    }
    return 0;
}