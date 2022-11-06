#include<bits/stdc++.h>

using ll = long long;
using ld = long double;

namespace GTI
{
	char gc(void)
   	{
		const int S = 1 << 16;
		static char buf[S], *s = buf, *t = buf;
		if (s == t) t = buf + fread(s = buf, 1, S, stdin);
		if (s == t) return EOF;
		return *s++;
	}
	ll gti(void)
   	{
		ll a = 0, b = 1, c = gc();
		for (; !isdigit(c); c = gc()) b ^= (c == '-');
		for (; isdigit(c); c = gc()) a = a * 10 + c - '0';
		return b ? a : -a;
	}
	int gts(char *s)
   	{
		int len = 0, c = gc();
		for (; isspace(c); c = gc());
		for (; c != EOF && !isspace(c); c = gc()) s[len++] = c;
		s[len] = 0;
		return len;
	}
	int gtl(char *s)
   	{
		int len = 0, c = gc();
		for (; isspace(c); c = gc());
		for (; c != EOF && c != '\n'; c = gc()) s[len++] = c;
		s[len] = 0;
		return len;
	}
}
using GTI::gti;
using GTI::gts;
using GTI::gtl;

const int N = 3e5 + 501;
std::vector<int> edges[N];
void addedge(int u, int v)
{
	edges[u].push_back(v);
	edges[v].push_back(u);
}

int val[N], cnt;
void dfs(int v, int n, int fa = 0, int rv = 0)
{
	if (fa == 0)
		val[v] = n, ++cnt;
	else if (v <= n)
		val[v] = val[fa] ^ n;
	else
	{
		if (rv >= n) val[v] = cnt + n;
		else val[v] = cnt;
		++cnt;
	}
	for (auto u : edges[v])
		if (u != fa)
			dfs(u, n, v, rv ^ val[v]);
}
int main(void)
{
	for (int T = gti(); T; T--)
	{
		int n = (1 << gti());
		for (int i = 1; i <= n * 2; i++)
			edges[i].clear();
		for (int i = 1; i < n; i++)
		{
			addedge(gti(), i + n);
			addedge(gti(), i + n);
		}
		cnt = 0;
		dfs(1, n);
		printf("1\n");
		for (int i = 1; i <= n; i++)
			printf("%d ", val[i]);
		puts("");
		for (int i = 1; i < n; i++)
			printf("%d ", val[i + n]);
		puts("");
	}
}