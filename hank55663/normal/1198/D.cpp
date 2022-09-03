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
#define less Less
#define EPS 1e-4
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 30005
#define next Next
#define index Index
int dp[55][55][55][55];
int pre[55][55];
int DP(int x1,int y1,int x2,int y2){
    if(dp[x1][y1][x2][y2]!=-1)return dp[x1][y1][x2][y2];
    if(pre[x2][y2]-pre[x1-1][y2]-pre[x2][y1-1]+pre[x1-1][y1-1]==0){
      //  printf("%d %d %d %d\n",x1,y1,x2,y2);
        return dp[x1][y1][x2][y2]=0;
    }
    dp[x1][y1][x2][y2]=max(x2-x1+1,y2-y1+1);
    for(int i = x1;i<x2;i++){
        dp[x1][y1][x2][y2]=min(dp[x1][y1][x2][y2],DP(x1,y1,i,y2)+DP(i+1,y1,x2,y2));
    }
    for(int i =y1;i<y2;i++){
        dp[x1][y1][x2][y2]=min(dp[x1][y1][x2][y2],DP(x1,y1,x2,i)+DP(x1,i+1,x2,y2));
    }
  //  printf("%d %d %d %d %d\n",x1,y1,x2,y2,dp[x1][y1][x2][y2]);
    return dp[x1][y1][x2][y2];
}
int main(){
    MEMS(dp);
    int n;
    scanf("%d",&n);
    char c[55][55];
    for(int i = 1;i<=n;i++){
        scanf("%s",c[i]+1);
        for(int j = 1;j<=n;j++){
            if(c[i][j]=='#'){
                pre[i][j]=1;
            }
            else{
                pre[i][j]=0;
            }
            pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+pre[i][j];
        }
    }
    printf("%d\n",DP(1,1,n,n));
}
/*

100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */