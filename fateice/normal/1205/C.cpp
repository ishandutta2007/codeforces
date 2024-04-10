#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,x[60][60],y[60][60],f[60][60][60][60],g[60][60][60][60];
inline void dp(int i,int j,int k,int l)
{
    if(f[i][j][k][l]!=-1)
      return;
    if(k+l-i-j<=1)
      {
       f[i][j][k][l]=(x[i][j]==x[k][l]);
       g[i][j][k][l]=(y[i][j]==y[k][l]);
       return;
      }
    f[i][j][k][l]=g[i][j][k][l]=0;
    if(k-1>=i+1)
      {
       dp(i+1,j,k-1,l);
       f[i][j][k][l]|=(x[i][j]==x[k][l] && f[i+1][j][k-1][l]);
       g[i][j][k][l]|=(y[i][j]==y[k][l] && g[i+1][j][k-1][l]);
      }
    if(k-1>=i && l>=j+1)
      {
       dp(i,j+1,k-1,l);
       f[i][j][k][l]|=(x[i][j]==x[k][l] && f[i][j+1][k-1][l]);
       g[i][j][k][l]|=(y[i][j]==y[k][l] && g[i][j+1][k-1][l]);
       dp(i+1,j,k,l-1);
       f[i][j][k][l]|=(x[i][j]==x[k][l] && f[i+1][j][k][l-1]);
       g[i][j][k][l]|=(y[i][j]==y[k][l] && g[i+1][j][k][l-1]);
      }
    if(l-1>=j+1)
      {
       dp(i,j+1,k,l-1);
       f[i][j][k][l]|=(x[i][j]==x[k][l] && f[i][j+1][k][l-1]);
       g[i][j][k][l]|=(y[i][j]==y[k][l] && g[i][j+1][k][l-1]);
      }
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k,l,w;
	scanf("%d",&n);
	x[1][1]=1;
	printf("? 1 1 2 2\n");
    fflush(stdout);
    scanf("%d",&k);
    x[2][2]=x[1][1]^k^1;
	for(i=1;i<=n;i++)
	  for(j=1+(i+1&1);j<=n;j+=2)
	    if(!(i+j==2 || i+j==2*n || i==2 && j==2))
	      if(i>2)
	        {
             printf("? %d %d %d %d\n",i-2,j,i,j);
             fflush(stdout);
             scanf("%d",&k);
             x[i][j]=x[i-2][j]^k^1;
            }
          else
	        {
             printf("? %d %d %d %d\n",i,j-2,i,j);
             fflush(stdout);
             scanf("%d",&k);
             x[i][j]=x[i][j-2]^k^1;
            }
    x[1][2]=1;
    printf("? 1 2 2 3\n");
    fflush(stdout);
    scanf("%d",&k);
    x[2][3]=x[1][2]^k^1;
    printf("? 2 1 2 3\n");
    fflush(stdout);
    scanf("%d",&k);
    x[2][1]=x[2][3]^k^1;
    for(i=1;i<=n;i++)
	  for(j=1+(i&1);j<=n;j+=2)
	    if(!(i+j==3 || i==2 && j==3))
	      if(i>2)
	        {
             printf("? %d %d %d %d\n",i-2,j,i,j);
             fflush(stdout);
             scanf("%d",&k);
             x[i][j]=x[i-2][j]^k^1;
            }
          else
	        {
             printf("? %d %d %d %d\n",i,j-2,i,j);
             fflush(stdout);
             scanf("%d",&k);
             x[i][j]=x[i][j-2]^k^1;
            }
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        y[i][j]=x[i][j]^(i+j&1);
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        for(k=i;k<=n;k++)
          for(l=j;l<=n;l++)
            f[i][j][k][l]=g[i][j][k][l]=-1;
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        for(k=i;k<=n;k++)
          for(l=j;l<=n;l++)
            if(f[i][j][k][l]==-1)
              dp(i,j,k,l);
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        for(k=i;k<=n;k++)
          for(l=j;l<=n;l++)
            if(k+l-i-j>=2 && f[i][j][k][l]!=g[i][j][k][l])
              {
    printf("? %d %d %d %d\n",i,j,k,l);
    fflush(stdout);
    scanf("%d",&w);
    printf("!\n");
    if(w==f[i][j][k][l])
      for(i=1;i<=n;i++)
        {
         for(j=1;j<=n;j++)
           printf("%d",x[i][j]);
         printf("\n");
        }
    else
      for(i=1;i<=n;i++)
        {
         for(j=1;j<=n;j++)
           printf("%d",y[i][j]);
         printf("\n");
        }
	return 0;
    }
    return 0;
}