#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a[4];
		scanf("%d%d%d",&a[1],&a[2],&a[3]);
		sort(a+1,a+4);
		int tmp=0;
		if(a[1]+a[2]>a[3])
		{
			tmp=min(a[1],(a[1]+a[2]-a[3])/2);
		}
		printf("%d\n",min(a[1]+a[2],a[3])+tmp);
	}
}