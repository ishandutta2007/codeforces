#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100005],i,p[100005],ans,f[100005];
int main()
{
	 scanf("%d",&n);
	 for (i=1;i<=n;++i) scanf("%d",&a[i]),p[a[i]]=i;
	 for (i=1;i<=n;++i)
	 {
	    f[i]=max(f[i],f[p[a[i]-1]]+1);
		ans=max(ans,f[i]);
	  }
	 printf("%d\n",n-ans);
}