#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
LL dp[2000005];
LL fra[4000005];
LL inv[4000005];
int mod=998244353;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
LL C(LL a,LL b){
    return fra[a]*inv[b]%mod*inv[a-b]%mod;
}
LL invC(LL a,LL b){
    return inv[a]*fra[b]%mod*fra[a-b]%mod;
}
void solve(){
    fra[0]=1;
    for(int i = 1;i<=4000000;i++)fra[i]=fra[i-1]*i%mod;
    inv[4000000]=f_pow(fra[4000000],mod-2)%mod;
    for(int i = 3999999;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
    dp[0]=0;
    int n,m;
    scanf("%d %d",&n,&m);
    LL tmp=0;
    for(int i = 0;i<=n;i++){
        tmp+=(i+1)*C(n-i+m-1,m-1)%mod*invC(n+m,m)%mod;
      //  printf("%lld %lld %lld %d %d\n",tmp,C(n-i+m-1,m-1),invC(n+m,m),n-i+m-1,m-1);
    }
  //  printf("%lld\n",tmp);
    LL sum=0;
    for(int i = 1;i<=n;i++){

        //(1-C(i+m-1,m-1)*invC(i+m,m)%mod)*f[i]=sum*invC(i+m,m)+tmp;
        dp[i]=(sum*invC(i+m,m)+tmp)%mod*f_pow( (1-C(i+m-1,m-1)*invC(i+m,m)%mod+mod)%mod,mod-2)%mod;
        sum+=dp[i]*C(i+m-1,m-1)%mod;
        sum%=mod;
    }
    printf("%lld\n",dp[n]);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/