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
void solve(){
    int n;
    scanf("%d",&n);
    char c[505];
    int x[505];
    for(int i = 0;i<n;i++){
        scanf(" %c",&c[i]);
        if(c[i]=='+')scanf("%d",&x[i]);
    }
    LL ans=0;
    for(int i = 0;i<n;i++){
        if(c[i]=='+'){
            int dp[505];
            fill(dp,dp+505,0);
            dp[0]=1;
            for(int j = 0;j<n;j++){
                if(c[j]=='+'){
                    if(x[j]<x[i]||(x[j]==x[i]&&j<i)){
                        for(int k=n-1;k>=1;k--){
                            dp[k]+=dp[k-1];
                            dp[k]%=mod;
                        }
                    }
                    else if(j!=i){
                        for(int k = 0;k<n;k++){
                            dp[k]=dp[k]*2%mod;
                        }
                    }
                }
                else{
                    if(j<i){
                        dp[0]=dp[0]*2%mod;
                        for(int k = 0;k<n;k++)dp[k]+=dp[k+1],dp[k]%=mod;
                    }
                    else if(j>i){
                        for(int k = 0;k<n;k++)dp[k]+=dp[k+1],dp[k]%=mod;
                    }
                }
            }
            for(int j = 0;j<n;j++)ans+=dp[j]*1ll*x[i]%mod,ans%=mod;
        }
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}