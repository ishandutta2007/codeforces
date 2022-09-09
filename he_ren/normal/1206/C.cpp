#include<cstdio>
typedef long long ll;

int main(void)
{
	int n;
	scanf("%d",&n);
	if((n&1) == 0)
	{
		printf("NO");
		return 0;
	}
	printf("YES\n");
	for(int i=1; i<=n; ++i)
	{
		int x=i*2;
		if(i&1) printf("%d ",x-1);
		else printf("%d ",x);
	}
	for(int i=1; i<=n; ++i)
	{
		int x=i*2;
		if(i&1) printf("%d ",x);
		else printf("%d ",x-1);
	}
	return 0;
}