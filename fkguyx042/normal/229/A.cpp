#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int Inf=(int)1e9;
int i,j,m,n,p,k,Ans[10001];
int G[101][10001];
char c[101][10001];
int main()
{scanf("%d%d",&n,&m); memset(G,60,sizeof(G));
  for (i=1;i<=n;i++)
  {   scanf("%s",&c[i]);
      for (j=m;j>=1;j--) if (c[i][j-1]=='1') break;
        if (j==0) { printf("-1\n"); return 0;}
        G[i][1]=(m-j)+1;
        for (j=1;j<=m;j++)
        G[i][j]=min(G[i][j],min(j==1?Inf:G[i][j-1]+1,c[i][j-1]=='1'?0:Inf));
      for (j=1;j<=m;j++)
        if (c[i][j-1]=='1') break;
        G[i][m]=min(G[i][m],j);
        for (j=m;j;j--)
          G[i][j]=min(G[i][j],min(j==m?Inf:G[i][j+1]+1,c[i][j-1]=='1'?0:Inf));
}
int ans=Inf;
  for (i=1;i<=m;i++){
    for (j=1;j<=n;j++)
      Ans[i]+=G[j][i]; ans=min(ans,Ans[i]);
}
printf("%d\n",ans);
}