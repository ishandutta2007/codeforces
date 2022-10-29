#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 155

using namespace std;
const int inf=(int)1e9;
int i,j,m,n,p,k,a[N],f[N][N][N],best[N][N],l,syc;
char c[N];
void up(int &x,int y,int z)
{
	 if (y<0||z<0) return;
	 x=max(x,y+z);
}
int main()
{
	  scanf("%d",&n);
	  for (i=1;i<=n;++i) scanf("%d",&a[i]);
	  scanf("%s",c);
	  for (i=n;i;--i) c[i]=c[i-1];
	  for (i=1;i<=n;++i)
	    for (j=1;j<=n;++j)
	      for (k=0;k<=n;++k) f[i][j][k]=-inf;
	  memset(best,0,sizeof(best));
	  for (i=1;i<=n;++i) 
	  {
	  	  best[i][i]=max(0,a[1]);
		  f[i][i][1]=0;
		  if (a[1]>=0)
		  f[i][i][0]=a[1];
	  }
	  for (l=2;l<=n;++l)
	     for (j=1;j<=n-l+1;++j)
	     {
	     	  k=j+l-1;
	     	    for (i=j;i<k;++i)
	     	      best[j][k]=max(best[j][k],best[j][i]+best[i+1][k]);
	     	    for (i=0;i<=l;++i)
				   for (syc=j;syc<k;++syc)
				      up(f[j][k][i],f[j][syc][i],f[syc+1][k][0]),
					  up(f[j][k][i],f[j][syc][0],f[syc+1][k][i]);
				for (i=2;i<=l;++i)
				  if (c[j]==c[k])
				  {
				  	  if (l==2) f[j][k][2]=0;
				  	  else up(f[j][k][i],f[j+1][k-1][i-2],0);
				  }
			   for (i=l;i;--i)
			      up(f[j][k][0],f[j][k][i],a[i]);
			   for (i=0;i<=l;++i)
			      best[j][k]=max(best[j][k],f[j][k][i]); 
		 }
	  printf("%d\n",best[1][n]);
}