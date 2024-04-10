#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <ctime>
#include <cmath>

using namespace std;

int levels[1000002],n,m,mod;
int dp[5001][5001],dp2[2][5002];
int C[5002],Fact[5005];

int mpow(int a,int x)
{
    int ret=1;
    while(x)
    {
        if (x&1) ret=(1LL*ret*a)%mod;
        a=(1LL*a*a)%mod; x>>=1;
    }
    return ret;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    scanf("%d%d%d",&n,&m,&mod);
    for(int i=0;i<n;i++)
        scanf("%d",&levels[i]);
    dp[0][0]=1;
    int MAX=5000;
    for(int len=0;len<MAX;++len) {
        for(int col=0;col<=MAX;++col) {
            if (dp[len][col]) {
                if (col==0) dp[len+1][col+1]=1;
                if (col==1) {
                    dp[len+1][col+1]+=dp[len][col];
                    if (dp[len+1][col+1]>=mod) dp[len+1][col+1]-=mod;
                }
                if (col>1) {
                    dp[len+1][col]=(dp[len+1][col]+1LL*(col-1)*dp[len][col])%mod;
                    dp[len+1][col+1]+=dp[len][col];
                    if (dp[len+1][col+1]>=mod) dp[len+1][col+1]-=mod;
                }
            }
        }
    }
//  cout << dp[3][2] << "   " << dp[1][1] << "  " << dp[2][2] << endl;
    C[0]=Fact[0]=1;
//-----------------------------
    for(int i=1;i<=5000&&i<=m;i++) {
        C[i]=1LL*C[i-1]*(m-i+1)%mod;
        Fact[i]=(1LL*Fact[i-1]*i)%mod;
    }
//-----------------------------
    int ans=0,cur=0,next=1,sum=1,last=0;
    dp2[0][0]=1;
    for(int i=0;i<n;i++) {
//        memset(dp2[next],0,sizeof(dp2[next]));
        for(int j=0;j<=levels[i];++j) {
            dp2[next][j]=1LL*dp[levels[i]][j]*C[j]%mod*(sum-dp2[cur][j])%mod;
            dp2[next][j]=(dp2[next][j]+1LL*dp[levels[i]][j]*(C[j]-Fact[j])%mod*dp2[cur][j])%mod;
            while (dp2[next][j]<0) dp2[next][j]+=mod;
        }
        sum=0;
        for(int j=0;j<=levels[i];++j) sum=(sum+dp2[next][j])%mod;
        cur^=1; next^=1;
       if (i>0) for(int j=0;j<=levels[i-1];j++)
                  dp2[next][j]=0;  
    }
    for(int j=0;j<=levels[n-1];++j)
        ans=(ans+dp2[cur][j])%mod;
    printf("%d\n",ans);
    return 0;
}