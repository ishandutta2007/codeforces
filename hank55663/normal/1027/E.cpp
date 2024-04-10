#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL;
int dp[505][505];
int mod=998244353;
int main(){
    int n,K;
    scanf("%d %d",&n,&K);
  /*  if(K==1){
        printf("0\n");
        return 0;
    }*/
    for(int i=1;i<=n;i++){
        dp[i][0]=2;
        for(int j=1;j<=n;j++){
            for(int k=max(0,j-i);k<j;k++)
                dp[i][j]=(dp[i][j]+dp[i][k])%mod;
        //    printf("%d ",dp[i][j]);
        }
        for(int j=1;j<i;j++)
        dp[i][n]-=dp[j][n];
        //printf("\n");
     //   printf("%d ",dp[i][n]);
    }
  //  printf("\n");
    LL ans=0;
    for(int i=1;i<=n;i++){
        int ddp[505];
        MEM(ddp);
        int need=(K+i-1)/i;
        ddp[0]=dp[i][n];
        for(int j=1;j<=n;j++){
            for(int k=max(0,j-need+1);k<j;k++){
                ddp[j]=(ddp[j]+ddp[k])%mod;
            }
           // printf("%d ",ddp[j]);
        }
        ans+=ddp[n];
        ans%=mod;
      //  printf("%d %d\n",ddp[n],need);
    }
    printf("%lld\n",ans);
}