#include<bits/stdc++.h>
#define maxn 2505

using namespace std;
const int inf=20304050;
char s[maxn*5];
int n,ans,a,b,p,w,dp[maxn*2][maxn][2],c[maxn*2];

void solve(int l,int r,int o)
{
    int p1,p2,mid;
    c[o]=(r-l)/4;
    if (l==r) {dp[o][0][0]=dp[o][0][1]=s[l]-'0';return;}
    w=0; for (int i=l+1;i<r;i++) if (s[i]=='(') w++; else if (s[i]==')') w--; else if (!w&&s[i]=='?') mid=i;
    p1=p; solve(l+1,mid-1,p++); p2=p; solve(mid+1,r-1,p++);
    for (int i=0;i<=c[o];i++) dp[o][i][0]=-inf,dp[o][i][1]=inf;
    for (int i=0;i<=c[p1];i++) for (int j=0;j<=c[p2];j++) {
        dp[o][i+j+1][0]=max(dp[o][i+j+1][0],dp[p1][i][0]+dp[p2][j][0]);
        dp[o][i+j][0]=max(dp[o][i+j][0],dp[p1][i][0]-dp[p2][j][1]);
        dp[o][i+j+1][1]=min(dp[o][i+j+1][1],dp[p1][i][1]+dp[p2][j][1]);
        dp[o][i+j][1]=min(dp[o][i+j][1],dp[p1][i][1]-dp[p2][j][0]);
    }
}

int main()
{
    scanf("%s",s); n=strlen(s);
    scanf("%d%d",&a,&b);p=0;
    solve(0,n-1,p++);
    printf("%d\n",dp[0][a][0]);
}