#include<cstdio>

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=n; ++j)
		{
			if((i&1)==(j&1)) putchar('W');
			else putchar('B');
		}
		putchar('\n');
	}
	return 0;
}