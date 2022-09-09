#include<cstdio>

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d %d\n",l,l<<1);
	}
	return 0;
}