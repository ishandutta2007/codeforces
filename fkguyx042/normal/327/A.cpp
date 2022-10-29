#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,a[105],ans;
int main()
{
	 scanf("%d",&n);
	 for (i=1;i<=n;++i) scanf("%d",&a[i]);
	 for (i=1;i<=n;++i)
	   for (j=i;j<=n;++j)
	   {
	   	  int sum=0;
	   	  for (k=i;k<=j;++k) a[k]=1-a[k];
	   	  for (k=1;k<=n;++k)
	   	    if (a[k]) ++sum;
	   	  ans=max(ans,sum);
          for (k=i;k<=j;++k) a[k]=1-a[k];
       }
      printf("%d\n",ans);
}