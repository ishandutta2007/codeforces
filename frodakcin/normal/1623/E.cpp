#include <cstdio>

const int MN = 2e5+10;

int N, K, l[MN], r[MN], o[MN], ctr, loc[MN];
char s[MN];
bool dup[MN], bad[MN];

void dfs(int n)
{
	if(l[n]) dfs(l[n]);
	loc[n] = ctr;
	o[ctr++] = n;
	if(r[n]) dfs(r[n]);
}

int solve(int n, int k)
{
	if(n==0) return 0;
	int v = solve(l[n], k-1);
	if(v > 0 || (k>0 && bad[n]))
	{
		dup[n] = 1;
		return v+1+solve(r[n], k-v-1);
	}
	return 0;
}

int main()
{
	scanf("%d%d", &N, &K);
	scanf(" %s", s+1);
	for(int i=1;i<=N;++i)
		scanf("%d%d", l+i, r+i);
	dfs(1);
	o[N] = N+1;

	char p = 0;
	for(int i=N-1;i>=0;--i)
	{
		if(s[o[i]] != s[o[i+1]])
			p = s[o[i+1]];
		bad[o[i]] = s[o[i]] < p; // want to duplicate
	}

	solve(1, K);

	for(int i=0;i<N;++i)
		for(int j=0;j<1+dup[o[i]];++j)
			printf("%c", s[o[i]]);
	printf("\n");
	return 0;
}