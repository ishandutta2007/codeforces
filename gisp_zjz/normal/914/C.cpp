#include<bits/stdc++.h>
#define maxn 2500
#define mod 1000000007

using namespace std;
typedef long long ll;

ll dp[maxn][maxn],r[maxn],ans,t,n,k;
char s[maxn];

int c(int x)
{
    int tmp=0;
    while (x)
    {
        if (x&1) tmp++;
        x>>=1;
    }
    return tmp;
}

int main()
{
    scanf("%s",s);
    scanf("%d",&k);
    if (k==0) {printf("1\n");return 0;}
    if (k==1) {printf("%d\n",strlen(s)-1);return 0;}
    r[1]=0;
    for (int i=2;i<=1000;i++)
        r[i]=r[c(i)]+1;
    dp[0][0]=1;
    for (int i=1;i<=1000;i++)
    {
        dp[i][0]=dp[i][i]=1;
        for (int j=1;j<i;j++)
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
    }
    ans=0;n=strlen(s);t=0;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='1'){
            for (int j=0;j<n-i;j++)
                if (r[j+t]==k-1) ans=(ans+dp[n-i-1][j])%mod;
            t++;
        }
    }
    if (r[t]==k-1) ans=(ans+1)%mod;
    printf("%d\n",ans);
    return 0;
}