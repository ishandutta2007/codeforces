#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>
#include <memory.h>
#include <algorithm>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

int t[4002],d[4002];
int dp[4002][4002];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,k,last=0;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i)
        scanf("%d%d",&t[i],&d[i]);
    int ans=0,F=86401;
    if (n==0) ans=86400;
    for(int i=0;i<=n;++i)
        for(int j=0;j<=k;++j)
            dp[i][j]=F;
    dp[0][0]=0;
    for(int i=0;i<n;++i)
        for(int j=0;j<=k;++j) {
            dp[i+1][j]=min(dp[i+1][j],max(t[i]+d[i]-1,dp[i][j]+d[i]));
            if (j<k) dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
        }
    for(int i=0;i<=n;++i)
        for(int j=0;j<=k;++j)
            ans=max(ans,(i+k-j<n ? t[i+k-j] : F)-dp[i][j]-1);
    printf("%d\n",ans);
    return 0;
}