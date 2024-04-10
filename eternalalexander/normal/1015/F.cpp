#include <cstdio>
#include <cstring>
#include <algorithm>
const int mod=1e9+7;

/*
dp[i][j][k]ij,k.
*/
int next[205];
long long dp[205][205][205][2];
char s[300];

int main() {
    int n; scanf("%d", &n);
    scanf("%s", &s); 
    int m=std::strlen(s); int cnt=0;
    for (int i=m;i>=1;i--) s[i]=s[i-1];
    for (int i = 2, j = 0; i<=m;++i) {
        while (j&&s[j+1]!=s[i]) j=next[j];
        if (s[j+1]==s[i]) j++;
        next[i]=j;
    }//printf("%d", m);
    std::memset(dp, 0, sizeof(dp));
    dp[1][0][0][0]=1;
    n*=2;
    long long ans=0;
    for (int i=1;i<=n+1;++i) {
        for (int j=0;j<=i;++j) {
            //printf("%d ", dp[i][j][m][0]);
            dp[i][j][m][1]=(dp[i][j][m][1]+dp[i][j][m][0])%mod;
            dp[i][j][m][0]=0;
            for (int k=0;k<=i&&k<=m;++k) {
                if (i==n+1&&j==0) ans+=dp[i][j][k][1];
                ans=ans%mod; //printf("%d ", dp[i][j][k][1]);
                for (int l=0;l<=1;++l) {
                    int p=k; while (p!=0&&s[p+1]!=')') p=next[p];
                    if (s[p+1]==')') p+=1;
                    if (j>0) dp[i+1][j-1][p][l]=(dp[i+1][j-1][p][l]+dp[i][j][k][l])%mod;
                    p=k; while (p!=0&&s[p+1]!='(') p=next[p];
                    if (s[p+1]=='(') p+=1;
                    dp[i+1][j+1][p][l]=(dp[i+1][j+1][p][l]+dp[i][j][k][l])%mod;
                }
            }
        }//printf("\n");
    }printf("%lld", ans);
   // for (int i=1;i<=m;++i) printf("%d ", next[i]);
    return 0;
}