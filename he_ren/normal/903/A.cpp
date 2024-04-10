#include<cstdio>

void solve()
{
	int x;
	scanf("%d",&x);
	for(int i=0; i<=x; i+=3)
		for(int j=0; j<=x; j+=7)
			if(i+j==x)
			{
				printf("YES\n");
				return;
			}
	printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}