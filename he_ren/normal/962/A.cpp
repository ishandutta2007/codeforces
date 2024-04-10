#include<cstdio>
const int MAXN = 2e5 + 5;

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	int sum=0;
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]), sum+=a[i];
	
	sum=(sum+1)>>1;
	int now=0;
	for(int i=1; i<=n; ++i)
	{
		now+=a[i];
		if(now>=sum){ printf("%d",i); return 0;}
	}
	return 0;
}