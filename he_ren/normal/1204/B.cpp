#include<cstdio>

int main(void)
{
	int n,l,r;
	scanf("%d%d%d",&n,&l,&r);
	
	printf("%d %d",(1<<l)-1 + n-l, ((1<<r)-1) + (n-r)*(1<<(r-1)));
	return 0;
}