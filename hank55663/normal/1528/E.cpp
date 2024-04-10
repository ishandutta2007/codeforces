#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define last Last
#define MXN 200005
const int mod=998244353;
LL dp[1000005];
LL dp2[1000005];
LL dp3[1000005];
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
void solve(){

    dp[0]=1;
    dp2[0]=1;
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        dp[i]=((dp[i-1]+1)*dp[i-1]/2+dp[i-1]+1)%mod;
        dp2[i]=dp[i-1]*(dp[i-1]-1)%mod*(dp[i-1]+1)%mod*f_pow(6,mod-2)%mod+dp[i-1]*(dp[i-1]+1)%mod+dp[i-1]+1;
        dp2[i]%=mod;
        dp3[i]=(dp[i-1]*(dp[i-1]-1)/2%mod+dp[i-1])%mod;
      //  printf("%lld %lld %lld\n",dp3[i],dp2[i],dp[i]);
    }
    for(int i = n;i>=1;i--){
        dp[i]-=dp[i-1];
        dp2[i]-=dp2[i-1];
        dp[i]=(dp[i]+mod)%mod;
         dp2[i]=(dp2[i]+mod)%mod;
    }
    LL ans=(dp2[n]*2-1)%mod;
     //  printf("%lld\n",ans);
    for(int i=1;i<n-1;i++){
        ans+=(dp3[i]-dp3[i-1]+mod)%mod*dp3[n-i-1]%mod;
        ans%=mod;
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;//000;
    //scanf("%d",&t);
    while(t--)
        solve();
    /*int t=1;00000;
    scanf("%d",&t);
    while(t--){
        solve();
    }*/
}
/*
1 3 2 1
1 3 2 1
2 4 2 1
2 4 2 1
4 5 2 1
4 5 2 1
*/