#include<cstdio>
#include<algorithm>
using namespace std;
int i,a[100005],n;
int main()
{
	 scanf("%d",&n);
	 for (i=1;i<=n;++i) scanf("%d",&a[i]);
	 sort(a+1,a+n+1); if (a[n]==1) a[n]=2; else a[n]=1;
	 sort(a+1,a+n+1);
	 for(i=1;i<=n;++i) printf("%d ",a[i]);
}