#include<cstdio>

int main(void)
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,c,d,k;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		int x=(a+c-1)/c, y=(b+d-1)/d;
		if(x+y<=k) printf("%d %d\n",x,y);
		else printf("-1\n");
	}
	return 0;
}