#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,l,ans;
int A[555][555];
char c[555][555];
int main()
{
	 scanf("%d%d",&n,&m);
	 for (i=0;i<n;++i) scanf("%s",&c[i]);
	 for (i=n-1;i>=0;--i)
	   for (j=m-1;j>=0;--j)
	      if (c[i][j]=='W')
	      {
	      	  if (A[i][j]!=1)
	      	  {
	      	  	ans++;
	      	  	   int sm=1-A[i][j];
	      	  	   for (k=0;k<=i;++k)
	      	  	     for (l=0;l<=j;++l)
	      	  	       A[k][l]+=sm;
	      	  }
	      }
	      else 
	      {
	      	   if (A[i][j]!=-1)
	      	   {
	      	   	ans++;
	      	   	 int sm=-1-A[i][j];
	      	   	 	      	  	   for (k=0;k<=i;++k)
	      	  	     for (l=0;l<=j;++l)
	      	  	       A[k][l]+=sm;
	      	  	}
	      }
	      printf("%d\n",ans);
}