#include<cstdio>

int main(void)
{
	int n,k;
	scanf("%d%d",&n,&k);
	printf("%d",n+(k-n%k));
	return 0;
}