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

const int N = 2e5 + 501;
bool check(void)
{
	int n = gti();
	static char s[N];
	gts(s);
	std::vector<int> deg(n);
	std::vector<std::pair<int, int>> ans;
	auto addedge = [&](int u, int v)
	{
		deg[u] ^= 1, deg[v] ^= 1;
		ans.push_back({u, v});
	};
	for (int i = 0; i < n; i++)
		if (s[i] == '0')
			addedge(i, (i + 1) % n);
	int hd = -1;
	for (int i = 0; i < n; i++)
		if (deg[i] != s[i] - '0')
		{
			if (hd == -1) hd = i;
			else addedge(hd, i);
		}
	if (deg[hd] != s[hd] - '0') return false;
	puts("YES");
	for (auto [u, v] : ans)
		printf("%d %d\n", u + 1, v + 1);
	return true;
}

int main(void)
{
	for (int T = gti(); T; T--)
		if (!check()) puts("NO");
	return 0;
}