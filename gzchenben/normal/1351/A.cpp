#include<cstdio>
using namespace std;
int n,m,a[200005],b[200005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		printf("%d\n",a[i]+b[i]);
	}
}