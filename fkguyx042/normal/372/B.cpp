#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 45
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,l,q,sx,sy,ex,ey,ans;
char c[N];
int sum[N][N],f[N][N][N][N];
int check(int sx,int sy,int ex,int ey)
{
	  return (sum[ex][ey]-sum[sx-1][ey]-sum[ex][sy-1]+sum[sx-1][sy-1]==0);
}
int main()
{
	  scanf("%d%d%d",&n,&m,&q);
	  for (i=1;i<=n;++i)
	  {
	  	  scanf("%s",c);
	  	  for (j=1;j<=m;++j) sum[i][j]=c[j-1]-'0';
	  }
	  for (i=1;i<=n;++i) 
	     for (j=1;j<=m;++j) 
	  sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
	  for (i=1;i<=n;++i)
	     for (j=1;j<=m;++j)
	     {
	     	  if (i==1&&j==2) 
	     	    i=1;
	         for (k=1;i+k-1<=n;++k)
	             for (l=1;j+l-1<=m;++l)
	               if (check(i,j,i+k-1,j+l-1)) f[i][j][k][l]=1;
	         for (k=1;k<=n;++k)
	            for (l=1;l<=m;++l)
	               f[i][j][k][l]+=f[i][j][k-1][l]+f[i][j][k][l-1]-f[i][j][k-1][l-1];
	     }
	  for (;q--;)
	  {
	  	  ans=0;
	  	  scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
	  	  for (i=sx;i<=ex;++i)
	  	    for (j=sy;j<=ey;++j)
	  	        ans+=f[i][j][ex-i+1][ey-j+1];
	  	   printf("%d\n",ans);
	  }
}