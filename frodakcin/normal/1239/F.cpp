#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
//#define NDEBUG
#include <cassert>

const int MN = 5e5 + 100, MM = 5e5 + 100;
int N, M, deg[MN], d[MN], p[MN], t, q[MN], u[MN];
std::vector<int> a[MN];
std::vector<int> g[3];

bool dfs(int n)
{
	bool r = 0;
	for(int x : a[n])
		if(p[n] != x && deg[x]%3 == 2)
		{
			if(d[x])
				t = t?t:n, r = 1;
			else
				d[x] = d[n]+1, p[x] = n, r |= dfs(x);
		}
	return r;
}
bool forest(void)
{
	bool r = 1;
	for(int x : g[2])
		if(!d[x])
		{
			p[x] = -1, d[x] = 1;
			if(dfs(x)) r = 0;
		}
	return r;
}
std::vector<int> f;
void ans(void)
{
	std::sort(f.begin(), f.end());
	if(f.size() == N)
		printf("No\n");
	else
	{
		printf("Yes\n%d\n", N-f.size());
		for(int i = 1, j = 0, k = N-f.size();k;--k, ++i)
		{
			for(;i <= N && j < f.size() && f[j] == i;++i, ++j);
			printf("%d%c", i, " \n"[k==1]);
		}
	}
	f.clear();
}

void solve(void)
{
	scanf("%d%d", &N, &M);
	for(int i = 0, x, y;i < M;++i)
		scanf("%d%d", &x, &y), a[x].push_back(y), a[y].push_back(x), ++deg[x], ++deg[y];
	for(int i = 1;i <= N;++i)
		g[deg[i]%3].push_back(i);
	if(N == 1)
		printf("No\n");
	else if(!g[0].empty())
	{
		int x = g[0][0];
		printf("Yes\n%d\n", N-1);
		for(int i = 1;i < N;++i)
			printf("%d%c", i+(i>=x), " \n"[i+1==N]);
	}
	else if(!forest())
	{
		int n, v = 0;
		for(int x : a[t])
			if(x != p[t] && d[x])
				if(d[t] > d[x] && d[x] > v)
					n = x, v = d[x];
		f.push_back(n), f.push_back(t);
		for(int i = p[t], x, y;i != n;i = x)
		{
			f.push_back(i);
			y = d[i];
			for(int z : a[i])
				if(y > d[z] && d[z] >= v)
					x = z, y = d[z];
		}
		ans();
	}
	else if(g[1].empty())
		printf("No\n");
	else if(g[1].size() >= 2)
	{
		u[g[1][0]] = -1;
		q[0] = g[1][0];
		for(int i = 0, j = 1, n = q[0];i < j;n = q[++i])
		{
			if(i && deg[n]%3 == 1)
			{
				t = n;
				break;
			}
			for(int x : a[n])
				if(!u[x])
					u[x] = n, q[j++] = x;
		}
		assert(t);
		for(int i = t;~i;i = u[i])
		{
			f.push_back(i);
			assert(f.size() <= N);
		}
		ans();
	}
	else
	{
		f.push_back(g[1][0]);
		int y = 0;
		t = a[g[1][0]][0];
		u[t] = -1, q[0] = t;
		for(int i = 0, j = 1, n = q[0];i < j;n = q[++i])
			for(int x : a[n])
				if(!u[x])
				{
					if(x == g[1][0])
						y = y||!i?y:n;
					else
						u[x] = n, q[j++] = x;
				}
		for(int i = y;~i;i = u[i])
		{
			f.push_back(i);
			assert(f.size() <= N);
		}
		y = 0;
		for(int x : a[g[1][0]]) if(!u[x]) {t = x;break;}
		u[t] = -1, q[0] = t;
		for(int i = 0, j = 1, n = q[0];i < j;n = q[++i])
			for(int x : a[n])
				if(!u[x])
				{
					if(x == g[1][0])
						y = y||!i?y:n;
					else
						u[x] = n, q[j++] = x;
				}
		for(int i = y;~i;i = u[i])
		{
			f.push_back(i);
			assert(f.size() <= N);
		}
		ans();
	}
	for(int i = 1;i <= N;++i) a[i].clear(), deg[i] = 0, p[i] = d[i] = u[i] = 0;
	for(int i = 0;i < 3;++i) g[i].clear();
	t = 0;
}

int T;
int main(void)
{
	scanf("%d", &T);
	for(int i = 1;i <= T;++i)
		solve();
	return 0;
}