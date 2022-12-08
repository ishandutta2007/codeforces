#include <cstdio>

const int MN = 15;
int N, a[MN], ctr, sum;
bool ok;

bool dfs(int n=0)
{
	if(ctr && !sum)
		return 1;
	if(n==N)
		return 0;
	for(int i=-1;i<=1;++i)
	{
		ctr += !!i;
		sum += a[n]*i;
		if(dfs(n+1)) return 1;
		ctr -= !!i;
		sum -= a[n]*i;
	}
	return 0;
}

void solve()
{
	scanf("%d", &N);
	for(int i=0;i<N;++i) scanf("%d", a+i);
	ok=0;
	ctr=sum=0;
	if(dfs())
		printf("YES\n");
	else
		printf("NO\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) solve();
}