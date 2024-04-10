#include<cstdio>
using namespace std;
int n,t,dif;
int main()
{
	scanf("%d",&t);
	for(int x=1;x<=t;x++)
	{
		dif=0;
		scanf("%d",&n);
		for(int i=1;i<=n/2-1;i++)
		{
			dif+=(1<<i);
		}
		for(int i=n/2;i<=n-1;i++)
		{
			dif-=(1<<i);
		}
		dif+=(1<<n);
		printf("%d\n",dif);
	}
}