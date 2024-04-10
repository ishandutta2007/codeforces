#include<bits/stdc++.h>
using namespace std;
typedef double db;
const int E=10000;
db tmp[105][10005],C[105][105],dp[2][105][20005],x,ans,S[105];
int n,d[105],c[105];
int main(){
    for (int i=0;i<105;i++){
        C[i][0]=C[i][i]=1;
        for (int j=1;j<i;j++) C[i][j]=C[i-1][j-1]+C[i-1][j];
    }
    cin >> n >> x;
    int sum=0;
    for (int i=1;i<=n;i++) {cin >> c[i];sum+=c[i];}
    for (int i=1;i<=n;i++) S[i]=(1.+((db)n/(n-i+1)-1)/2)*x;
    for (int i=1;i<=n;i++) d[i]=(int)((n-i+1)*(x*(1.+((db)n/(n-i+1)-1)/2)));
    d[n+1]=-1;
    dp[0][0][0]=1;
    for (int i=1;i<=n;i++){
        int o=i&1;
        for (int j=0;j<=i;j++)
            for (int k=0;k<=E;k++)
                dp[o][j][k]=0;
        for (int j=0;j<i;j++)
            for (int k=0;k<=E;k++){
                dp[o][j][k]+=dp[o^1][j][k];
                dp[o][j+1][k+c[i]]+=dp[o^1][j][k];
            }
    }
    ans=0;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=E;j++)
            ans+=min(S[i],(db)(sum-j)/(n-i+1))*dp[n&1][i-1][j]/C[n][i-1];
    printf("%.10f\n",ans);
    return 0;
}