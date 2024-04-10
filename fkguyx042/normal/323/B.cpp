#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 1005

using namespace std;
int a[N][N];
int i,j,m,n,p,k;
int main()
{
	scanf("%d",&n);
	if (n==1) printf("0\n");
	else if (n==2) printf("0 1\n1 0\n");
	else if (n==3) printf("0 1 0\n0 0 1\n1 0 0\n");
	else if (n==4) printf("-1\n");
	else 
	{
		  int flag=0;
		  if (!(n&1)) --n,flag=1;
		  for (i=0;i<n;++i)
		    for (j=1;j<=n/2;++j)
		     a[i][(i+j)%n]=1;
		  if (flag)
		  {
		  	 n++; 
		   for (i=0;i<n-1;++i) 
		    if (i&1) a[n-1][i]=1;
		    else a[i][n-1]=1;
		  }
		  for (i=0;i<n;++i)
		  {
		    for (j=0;j<n;++j) printf("%d ",a[i][j]);
		    puts("");
		  }
	}
}