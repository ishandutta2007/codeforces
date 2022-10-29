#include<cstdio>
#include<algorithm>

#define N 100005
int a[N],b[N],ans[N],i,x,m,n;
int main()
{
	 scanf("%d%d",&n,&m);
	 for (i=1;i<=n;++i) scanf("%d",&a[i]);
	 for (i=n;i;--i)
	 {
	 	 ans[i]=ans[i+1];
	 	 if (!b[a[i]]) ++ans[i];
	 	 ++b[a[i]];
	 }
	 for (;m--;)
	 {
	 	 scanf("%d",&x);
	 	 printf("%d\n",ans[x]);
	 }
}