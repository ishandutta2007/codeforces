#include<stdio.h>
#include<algorithm>
using namespace std;
int dp[31000][610];
int val[31000];
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int T=b;
    for(int i=0;i<a;i++){
        int p;scanf("%d",&p);
        val[p]++;
    }
    for(int i=0;i<31000;i++)for(int j=0;j<610;j++)dp[i][j]=-999999999;
    dp[b][300]=val[b];
    for(int i=b;i<30000;i++){
        for(int j=0;j<610;j++){
            if(dp[i][j]<0)continue;
            int sp=T+j-300;
            if(j&&sp>1&&i+sp-1<=30000)dp[i+sp-1][j-1]=max(dp[i+sp-1][j-1],dp[i][j]+val[i+sp-1]);
            if(i+sp<=30000)dp[i+sp][j]=max(dp[i+sp][j],dp[i][j]+val[i+sp]);
            if(j<609&&i+sp+1<=30000)dp[i+sp+1][j+1]=max(dp[i+sp+1][j+1],dp[i][j]+val[i+sp+1]);
        }
    }
    int ret=0;
    for(int i=0;i<31000;i++)for(int j=0;j<610;j++)ret=max(ret,dp[i][j]);
    printf("%d\n",ret);
}