#include<cstdio>
const int TOTSEC = 86400;

int main(void)
{
	int n,t;
	scanf("%d%d",&n,&t);
	for(int i=1; i<=n; ++i)
	{
		int a;
		scanf("%d",&a);
		
		int lft = TOTSEC-a;
		if(lft>=t)
		{
			printf("%d",i);
			return 0;
		}
		t-=lft;
	}
	return 0;
}