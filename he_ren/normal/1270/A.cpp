#include<cstdio>

void solve(void)
{
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	bool flag=0;
	for(int i=1; i<=a; ++i)
	{
		int x;
		scanf("%d",&x);
		if(x==n) flag=1;
	}
	for(int i=1; i<=b; ++i)
	{
		int x;
		scanf("%d",&x);
	}
	if(flag) printf("YES\n");
	else printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}