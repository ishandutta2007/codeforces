#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 300000
#define N 100005
LL pool[105][500005];
LL* dp[105];
int mod=1e9+7;
int main(){
    for(int i = 0;i<105;i++)
        dp[i]=pool[i]+250000;
    dp[0][0]=1;
    int a,b,k,t;
    scanf("%d %d %d %d",&a,&b,&k,&t);
    for(int i =1;i<=t;i++){
        LL sum=0;
        int l=-2*k*i,r=-2*k*i-1;
        for(int j=-2*k*i-2*k;j<=-2*k*i+2*k;j++){
            sum+=dp[i-1][j]*(2*k+1-abs(j+2*k*i))%mod;
            //printf("%lld %d\n",sum,j);
            sum%=mod;
        }
        for(int j=-2*k*i;j<=2*k*i+2*k+1;j++){
            dp[i-1][j]+=dp[i-1][j-1];
          //  printf("%lld ",dp[i-1][j]);
            dp[i-1][j]%=mod;
        }
     //   printf("\n");
        for(int j=-2*k*i;j<=2*k*i;j++){
            dp[i][j]=sum;
          //  printf("%d %d %lld\n",i,j,sum);
            sum-=dp[i-1][j]-dp[i-1][j-2*k-1];
            sum+=dp[i-1][j+2*k+1]-dp[i-1][j];
            sum=(sum%mod+mod)%mod;
        }
    }
    LL ans=0;
    for(int i=b-a+1;i<=t*k*2;i++)
        ans+=dp[t][i];
    printf("%lld\n",ans%mod);
}