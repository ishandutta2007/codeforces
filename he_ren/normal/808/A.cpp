#include<cstdio>

int a[15],cnt=0;

int main(void)
{
	int n;
	scanf("%d",&n);
	
	int t=n;
	while(t) a[++cnt]=t%10, t/=10;
	
	int ans=a[cnt]+1;
	for(int i=1; i<cnt; ++i) ans*=10;
	printf("%d",ans-n);
	return 0;
}