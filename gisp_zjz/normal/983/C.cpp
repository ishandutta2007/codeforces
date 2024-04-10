#include<bits/stdc++.h>
#define maxn 2001

using namespace std;
const int inf=1e9;
int dp[maxn][1000][10],n,a[maxn],b[maxn],d[1000],e[1000],p,h[1000][3],f[1000][3],ans,o[3];

int main()
{
    o[0]=1; o[1]=10; o[2]=100;
    for (int i=1;i<1000;i++) d[i]=d[i/10]+(i%10>0);
    for (int i=0;i<1000;i++){
        int tmp=i;
        for (int j=0;j<3;j++) h[i][j]=tmp%10,tmp/=10;
        if (d[i]==3) continue;
        if (i%10==0) e[i]=1;
        else if ((i/10)%10==0) e[i]=10;
        else e[i]=100;
    }
    for (int i=0;i<1000;i++){
        for (int j=0;j<3;j++)
            f[i][j]=i-h[i][j]*o[j];
    }
    scanf("%d",&n);
    for (int i=0;i<=n;i++) for (int j=0;j<1000;j++) for (int k=1;k<10;k++) dp[i][j][k]=inf;
    dp[0][0][1]=0;
    for (int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
    for (int i=0;i<=n;i++){
        p=a[i+1];
        for (int j=999;j>=0;j--){
            for (int k=1;k<10;k++){
                if (dp[i][j][k]>=inf) continue;
                for (int w=0;w<3;w++) if (h[j][w]) {
                    dp[i][f[j][w]][h[j][w]]=min(dp[i][f[j][w]][h[j][w]],dp[i][j][k]+abs(h[j][w]-k));
                }
                if (i==n) continue;
                if (d[j]<3) {
                    int r=j+e[j]*b[i+1];
                    dp[i+1][r][p]=min(dp[i+1][r][p],dp[i][j][k]+abs(p-k));
                }
                else {
                    dp[i+1][j][b[i+1]]=min(dp[i+1][j][b[i+1]],dp[i][j][k]+abs(k-p)+abs(p-b[i+1]));
                    for (int w=0;w<3;w++)
                    {
                        int r=f[j][w]+o[w]*b[i+1],s=h[j][w];
                        dp[i+1][r][s]=min(dp[i+1][r][s],dp[i][j][k]+abs(k-p)+abs(p-s));
                    }
                }
            }
        }
    }
    ans=inf;
    for (int i=1;i<10;i++) ans=min(ans,dp[n][0][i]);
    cout << ans+n*2 << endl;
    return 0;
}