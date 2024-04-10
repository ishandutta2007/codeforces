#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	long long ans=0,n,i,x;
	scanf("%I64d",&n);
	for (i=1;i<=n;++i)
	{
		 scanf("%I64d",&x);
		 ans+=1ll*(i-1)*(x-1)+x;
	}
	printf("%I64d\n",ans);
}