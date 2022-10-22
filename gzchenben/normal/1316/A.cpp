#include<cstdio>
#include<cstring>
#include<queue>
#include<stack> 
#include<algorithm>
using namespace std;
int n,m,t,sum,a[200005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		printf("%d\n",min(m,sum));
	}
	return 0;
}