#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>

const int MN = 2.5e5 + 100;

std::vector<int> a1[MN], a2[MN];
int N;

int p[MN][20];
int d[MN];
void dfs(int n = 1, int par = 0)
{
	p[n][0] = par;
	for(int i = 0;p[n][i]&&p[p[n][i]][i];++i)
		p[n][i+1] = p[p[n][i]][i];
	for(int x : a1[n])
		if(x != par)
			d[x] = d[n]+1, dfs(x, n);
}
struct DSU
{
public:
	int p[MN];
	int r[MN];
	int f(int n) {return p[n]?p[n]=f(p[n]):n;}
	bool m(int a, int b)
	{
		a = f(a), b = f(b);
		if(a==b) return 0;
		if(r[a]<r[b]) std::swap(a, b);
		p[b] = a;
		r[a] += r[a]==r[b], r[b]=0;
		return 1;
	}
};
DSU dsu;
int mu(int n, int d)
{
	for(int i = 0;1<<i <= d;++i)
		if(d&1<<i)
			n = p[n][i];
	return n;
}
int lca(int a, int b)
{
	if(d[a] < d[b]) std::swap(a,b);
	a=mu(a, d[a]-d[b]);
	if(a==b) return a;
	for(int i = 17;i >= 0;--i)
		if(p[a][i]&&p[a][i]!=p[b][i])
			a=p[a][i], b=p[b][i];
	return p[a][0];
}

void ans(int c, int pa)
{
	int l = lca(c, pa), k = dsu.f(l), z = dsu.f(c), v, i;
	if(z == k)
	{
		for(v = pa, i = 17;i >= 0;--i)
			if(d[v]-(1<<i) > d[l] && dsu.f(p[v][i]) != k)
				v = p[v][i];
	}
	else
	{
		for(v = c, i = 17;i >= 0;--i)
			if(d[v]-(1<<i) > d[l] && dsu.f(p[v][i]) == z)
				v = p[v][i];
	}
	printf("%d %d %d %d\n", v, p[v][0], c, pa);
	assert(dsu.m(v, p[v][0]));
}
void dfs2(int n = 1, int p = 0)
{
	for(int x : a2[n])
		if(x != p)
			dfs2(x, n);
	if(p)
		ans(n, p);
}
int main(void)
{
	scanf("%d", &N);
	for(int i = 0, x, y;i < N-1;++i)
		scanf("%d%d", &x, &y), a1[x].push_back(y), a1[y].push_back(x);
	for(int i = 0, x, y;i < N-1;++i)
		scanf("%d%d", &x, &y), a2[x].push_back(y), a2[y].push_back(x);
	dfs();
	printf("%d\n", N-1);
	dfs2();
	return 0;
}