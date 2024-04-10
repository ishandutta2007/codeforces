#include<cstdio>

int main(void)
{
	int n,x;
	scanf("%d%d",&n,&x);
	int sum=0;
	for(int i=1; i<=n; ++i)
	{
		int a;
		scanf("%d",&a);
		sum+=a;
	}
	
	if(sum+n-1 == x) printf("YES");
	else printf("NO");
	return 0;
}