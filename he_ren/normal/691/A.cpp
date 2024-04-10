#include<cstdio>

int main(void)
{
	int n;
	scanf("%d",&n);
	int s=0;
	for(int i=1; i<=n; ++i)
	{
		int x;
		scanf("%d",&x);
		s+=x;
	}
	
	if(n==1)
	{
		if(s==1) printf("YES");
		else printf("NO");
	}
	else
	{
		if(s==n-1) printf("YES");
		else printf("NO");
	}
	return 0;
}