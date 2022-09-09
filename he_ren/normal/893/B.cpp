#include<cstdio>

bool ok(int x)
{
	for(int i=2; i-1<=x; i<<=1)
	{
		int tmp = (i>>1) * (i-1);
		if(tmp>x) return 0;
		if(tmp==x) return 1;
	}
	return 0;
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=n; i>=1; --i)
		if(n%i==0 && ok(i))
		{
			printf("%d",i);
			break;
		}
	return 0;
}