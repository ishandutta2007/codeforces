#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MN = 2e5 + 10;
std::vector<int> a[MN], b[MN];
int N, M, ans;
bool u[MN], v[MN], c[MN];
char s[MN];
bool dfs(int n)
{
	u[n]=v[n]=1;
	for(int x : a[n])
	{
		if(u[x])
			return 0;
		if(v[x])
			continue;
		if(!dfs(x))
			return 0;
	}
	u[n]=0;
	return 1;
}
void dfsa(int n)
{
	c[n]=u[n]=1;
	for(int x : a[n])
		if(!u[x])
			dfsa(x);
}
void dfsb(int n)
{
	c[n]=v[n]=1;
	for(int x : b[n])
		if(!v[x])
			dfsb(x);
}
int main(void)
{
	scanf("%d%d", &N, &M);
	for(int i=0,x,y;i<M;++i)
		scanf("%d%d", &x, &y), a[x].push_back(y), b[y].push_back(x);
	for(int i=1;i<=N;++i)
		if(!v[i])
			if(!dfs(i))
				return printf("-1\n"), 0;
	memset(u, 0, sizeof u);
	memset(v, 0, sizeof v);
	for(int i=1;i<=N;++i)
	{
		s[i] = "AE"[c[i]];
		ans += !c[i];
		if(!u[i]) dfsa(i);
		if(!v[i]) dfsb(i);
	}
	printf("%d\n%s\n", ans, s+1);
	return 0;
}