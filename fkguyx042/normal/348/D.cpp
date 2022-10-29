#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int Mo=(int)1e9+7;
int i,j,m,n,p,k;
char c[3001][3001];
int dp[3001][3001];
int Go(int x,int y,int X,int Y)
{  memset(dp,0,sizeof(dp));
   if (c[x][y-1]=='#'||c[X][Y-1]=='#') return 0;
   dp[x][y]=1; int i,j;
   for (i=x;i<=X;i++)
      for (j=y;j<=Y;j++)
     if (i!=x||j!=y)
        if (c[i][j-1]=='#') dp[i][j]=0;
        else dp[i][j]=(dp[i-1][j]+dp[i][j-1])%Mo;
    return dp[X][Y];
}
int main()
{  scanf("%d%d",&n,&m);
   for (i=1;i<=n;i++)
      scanf("%s",&c[i]);
   printf("%d\n",(1ll*Go(1,2,n-1,m)*Go(2,1,n,m-1)%Mo+Mo-1ll*Go(1,2,n,m-1)*Go(2,1,n-1,m)%Mo)%Mo);
}