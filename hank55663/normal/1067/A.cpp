#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<assert.h>
#include<map>
#include<set>
#include<utility>
#include<iostream>
#include<cmath>
#include<sstream>
#include<queue>
#define LL long long
#define pll pair<LL,LL>
#define pii pair<int,int> 
#define pdd pair<double,double>
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define x first
#define y second
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
LL dp[100005][205][2];
int mod=998244353;
int main(){
    int n;
    scanf("%d",&n);
    MEM(dp);
    dp[0][1][0]=1;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        if(x==-1){
            LL sum=0;
            for(int xx=1;xx<=200;xx++){
                sum+=dp[i-1][xx-1][0]+dp[i-1][xx-1][1];
                sum%=mod;
                dp[i][xx][0]+=sum;
                dp[i][xx][0]%=mod;
                dp[i][xx][1]+=dp[i-1][xx][0]+dp[i-1][xx][1];
                dp[i][xx][1]%=mod;
            }
            sum=0;
            for(int xx=200;xx>=1;xx--){
                dp[i][xx][1]+=sum;
                sum+=dp[i-1][xx][1];
                sum%=mod;
                dp[i][xx][1]%=mod;
            }
        }
        else{
            for(int j=1;j<x;j++){
                dp[i][x][0]+=dp[i-1][j][0];
                dp[i][x][0]+=dp[i-1][j][1];
                dp[i][x][0]%=mod;
            }
            dp[i][x][1]+=dp[i-1][x][0]+dp[i-1][x][1];
            dp[i][x][1]%=mod;
            for(int j=x+1;j<=200;j++){
                dp[i][x][1]+=dp[i-1][j][1];
            }
        }
      //  for(int j=1;j<=10;j++)
        //printf("%d %d %d %d\n",i,j,dp[i][j][0],dp[i][j][1]);

    }
    LL ans=0;
    for(int j=1;j<=200;j++)
    ans+=dp[n][j][1],ans%=mod;
    printf("%lld\n",ans);
}