#include<bits/stdc++.h>
#define maxn 55
#define M 1000000007

using namespace std;
typedef long long ll;
ll dp[maxn][maxn][2][2][2],n,c[maxn],p[maxn],k,o,ans;

int main()
{
    scanf("%d%d",&n,&o);
    for (int i=0;i<n;i++) scanf("%d",&c[i]);
    dp[0][0][0][0][0]=1; p[0]=1; for (int j=1;j<maxn;j++) p[j]=p[j-1]*2%M;
    for (int i=0;i<n;i++)
        for (int j=0;j<=i;j++)
            for (int k=0;k<2;k++)
                for (int l=0;l<2;l++)
                    for (int w=0;w<2;w++){
                        if (c[i]!=1){
                            if (l){
                                 (dp[i+1][j][k][l][w]+=dp[i][j][k][l][w]*p[i-1])%=M;
                                 (dp[i+1][j][1][l][w^1]+=dp[i][j][k][l][w]*p[i-1])%=M;
                            }
                            else {
                                (dp[i+1][j][1][l][w^1]+=dp[i][j][k][l][w]*p[i])%=M;
                            }
                        }
                        if (c[i]!=0){
                            if (k){
                                (dp[i+1][j][k][l][w]+=dp[i][j][k][l][w]*p[i-1])%=M;
                                (dp[i+1][j][k][1][w^1]+=dp[i][j][k][l][w]*p[i-1])%=M;
                            }
                            else (dp[i+1][j][k][1][w^1]+=dp[i][j][k][l][w]*p[i])%=M;
                        }
                    }
    for (int i=0;i<=n;i++)
        for (int j=0;j<2;j++)
            for (int k=0;k<2;k++)
                (ans+=dp[n][i][j][k][o])%=M;
    cout << ans << endl;
    return 0;
}