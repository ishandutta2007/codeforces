#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<bitset>

#define N 505

using namespace std;
int f[N][N][2],n,ans,i,j,k,l;
int a[N];
void upd(int &x,int y)
{
	 x=min(x,y);
}
int main()
{
	 scanf("%d",&n);
	 for (i=1;i<=n;++i) scanf("%d",&a[i]);
	 memset(f,60,sizeof(f));
	 for (i=1;i<=n;++i)
	 {
	 	 f[i][i][0]=1;
	 	 f[i][i][1]=0;
	 }
	 for (l=2;l<=n;++l)
	   for (i=1;i<=n-l+1;++i)
	  {
	   	 j=i+l-1;
	     if (l==2&&a[i]==a[j]) 
		    f[i][j][1]=0;
		 for (k=i;k<j;++k)
		   upd(f[i][j][1],f[i][k][1]+f[k+1][j][0]),
		   upd(f[i][j][1],f[i][k][0]+f[k+1][j][1]),
		   upd(f[i][j][0],f[i][k][0]+f[k+1][j][0]);
		 if (a[i]==a[j]&&l>2) upd(f[i][j][1],f[i+1][j-1][0]),
		 upd(f[i][j][1],f[i+1][j-1][1]);
		 upd(f[i][j][0],f[i][j][1]+1);
	}
	printf("%d\n",f[1][n][0]);
}