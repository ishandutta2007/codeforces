#include <cstdio>
#include <vector>

const int MN = 2e5+20;
std::vector<int> a[MN];

void flip(int& x){x=-x;}
int c[MN], s[MN], N;

void dfs(int n, int p=0)
{
	s[n]=-1==c[n];
	for(int x:a[n])
		if(x!=p)
			dfs(x, n), s[n]+=s[x];
}

void solve(int n, int p=0)
{
	printf("%d ", n);
	flip(c[n]);
	bool dn = 0;
	for(int x:a[n])
		if(x!=p)
			if(s[x])
			{
				dn=1;
				solve(x, n);
				printf("%d ", n);
				flip(c[n]);
			}
	if(n==1) return;
	if(c[n] == -1)
	{
		printf("%d %d ", p, n);
		flip(c[n]);
		flip(c[p]);
	}
}
int main(void)
{
	scanf("%d", &N);
	for(int i=1;i<=N;++i)
		scanf("%d", c+i);
	for(int i=0,x,y;i+1<N;++i)
		scanf("%d%d", &x, &y), a[x].push_back(y), a[y].push_back(x);
	flip(c[1]);
	dfs(1);
	solve(1);
	if(c[1]==-1)
		printf("%d %d %d\n", a[1][0], 1, a[1][0]);
	return 0;
}