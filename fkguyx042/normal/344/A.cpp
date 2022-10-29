#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[1000005],n,i,ans;
int main()
{
	 scanf("%d",&n);
	 for (i=1;i<=n;++i)
	 {
	 	  scanf("%d",&a[i]);
	 	  if (a[i]!=a[i-1]) ++ans;
	 }
	 printf("%d\n",ans);
}