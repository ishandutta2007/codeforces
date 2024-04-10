#include<cstdio>

int main(void)
{
	int n;
	scanf("%d",&n);
	int spe=3;
	for(int i=1; i<=n; ++i)
	{
		int a;
		scanf("%d",&a);
		if(a==spe)
		{
			printf("NO");
			return 0;
		}
		spe = 6-spe-a;
	}
	printf("YES");
	return 0;
}