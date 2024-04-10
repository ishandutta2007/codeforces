#include<cstdio>
const int t[] = {6,2,5,5,4,5,6,3,7,6};

int main(void)
{
	int a,b;
	scanf("%d%d",&a,&b);
	int ans=0;
	for(int i=a; i<=b; ++i)
	{
		int x=i;
		while(x)
		{
			ans+=t[x%10];
			x/=10;
		}
	}
	printf("%d",ans);
	return 0;
}