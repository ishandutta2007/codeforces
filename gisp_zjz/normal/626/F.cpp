#include<bits/stdc++.h>
#define maxn 2010
#define M 1000000007

using namespace std;
typedef long long ll;
int dp[201][201][1001],n,m,ans,a[1050],x;

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1); dp[0][0][0]=1;
    for (int i=0;i<n;i++)
        for (int j=0;j<=i;j++)
            for (int k=0;k<=m;k++)
            {
                x=k+(a[i+1]-a[i])*j;
                if (x>m) continue;
                (dp[i+1][j+1][x]+=dp[i][j][k])%=M;
                dp[i+1][j][x]=(1ll*(j+1)*dp[i][j][k]+dp[i+1][j][x])%M;
                if (j) dp[i+1][j-1][x]=(1ll*j*dp[i][j][k]+dp[i+1][j-1][x])%M;
            }
    for (int i=0;i<=m;i++) (ans+=dp[n][0][i])%=M;
    cout << ans << endl;
    return 0;
}