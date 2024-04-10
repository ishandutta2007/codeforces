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
using namespace std;
int dp[2005][4005][2];
const int mod=1e9+7;
bool solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    char c[1000005];
    scanf("%s",c);
    int Min=0,sum=0;
    for(int i = 0;c[i]!=0;i++){
        if(c[i]==')')sum--;
        else sum++;
        Min=min(Min,sum);
    }
    if(Min<-2000||abs(sum)>2000){
        printf("0\n");
        return true;
    }
    dp[0][0][0]=1;
    if(Min==0){
        dp[0][sum][1]=1;
    }
    for(int i = 1;i<=n-m;i++){
        for(int j = 0;j<=2000;j++){
            dp[i][j][0]=((j==0?0:dp[i-1][j-1][0])+dp[i-1][j+1][0])%mod;
            dp[i][j][1]=((j==0?0:dp[i-1][j-1][1])+dp[i-1][j+1][1])%mod;
           // if(j-sum>=-Min&&j>=sum){
            //    dp[i][j][1]+=dp[i][j-sum][0];
            //     dp[i][j][1]%=mod;
            //}
          //  if(j<5)
           // printf("%d %d %d %d\n",i,j,dp[i][j][0],dp[i][j][1]);
        }
        for(int j = 0;j<=2000;j++){
            if(j-sum>=-Min&&j>=sum){
                 dp[i][j][1]+=dp[i][j-sum][0];
                 dp[i][j][1]%=mod;
            }
           // if(j<5)
           // printf("%d %d %d %d\n",i,j,dp[i][j][0],dp[i][j][1]);
        }
    }
    printf("%d\n",dp[n-m][0][1]);
    return true;
}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--)solve();//solve();
}
/*

4 7 2 1 7 4 3 1 7 2
*/