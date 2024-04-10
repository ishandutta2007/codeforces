#include<cstdio>
#include<cmath>
typedef long long ll;

void solve(void)
{
	int d;
	scanf("%d",&d);
	int sd = sqrt(2e9);
	for(int i=1; i<=sd; ++i)
	{
		int t = i*i-d;
		if(t<=0) continue;
		int st = sqrt(t);
		if(st*st != t) continue;
		
		int j = i/st;
		if(i/j==st)
		{
			printf("%d %d\n",i,j);
			return;
		}
	}
	printf("-1\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}