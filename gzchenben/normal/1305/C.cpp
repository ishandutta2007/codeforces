#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector> 
#include<algorithm>
using namespace std;
int n,m,a[200005];
long long ans=1;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(n>1000)
	{
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int tmp=abs(a[i]-a[j]);
			ans=ans*tmp%m;
		}
	}
	printf("%d\n",ans);
	return 0;
}