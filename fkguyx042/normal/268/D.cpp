#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 1005
#define H 31

using namespace std;
const int Mo=(int)1e9+9;
int f[N][2][H][H][H],ans,i,j,k,l,x,n,h;
void jia(int &x,int y)
{
	 x+=y; if (x>=Mo) x-=Mo;
}
int main()
{
	 scanf("%d%d",&n,&h);
	 f[1][0][1][1][1]=4;
	 for (i=1;i<=n;++i)
	  for (j=0;j<=1;++j)
	      for (k=0;k<=h;++k)
	        for (l=0;l<=h;++l)
	          for (x=0;x<=h;++x)
	           if (f[i-1][j][k][l][x])
	           {
	           	 jia(f[i][j][k<h?k+1:h][l<h?l+1:h][x<h?x+1:h],f[i-1][j][k][l][x]);
	           	 jia(f[i][k<h?0:1][j<1?1:h][l<h?l+1:h][x<h?x+1:h],f[i-1][j][k][l][x]);
	           	 jia(f[i][l<h?0:1][j<1?1:h][k<h?k+1:h][x<h?x+1:h],f[i-1][j][k][l][x]);
	           	 jia(f[i][x<h?0:1][j<1?1:h][k<h?k+1:h][l<h?l+1:h],f[i-1][j][k][l][x]);
	           }
	  for (j=0;j<=1;++j)
	      for (k=0;k<=h;++k)
	        for (l=0;l<=h;++l)
	          for (x=0;x<=h;++x)
	            if (j<1||k<h||l<h||x<h) jia(ans,f[n][j][k][l][x]);
	  printf("%d\n",ans);
}