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

struct DSU
{
    std::vector<int> fa;
    void init(int n)
    {
        fa.resize(n + 1);
        for (int i = 0; i <= n; i++)
            fa[i] = i;
    }
    int getfa(int v)
    {
        if (fa[v] == v) return v;
        return fa[v] = getfa(fa[v]);
    }
    void merge(int u, int v)
    {
        u = getfa(u), v = getfa(v);
        if (u == v) return;
        fa[u] = v;
    }
} dsu;
int main(void)
{
    for (int T = gti(); T; T--)
    {
        int n = gti();
        std::vector<int> a(n), b(n), c(n), loc(n + 1);
        std::vector<bool> vis(n);
        for (int i = 0; i < n; i++)
            a[i] = gti(), loc[a[i]] = i;
        for (int i = 0; i < n; i++)
            b[i] = gti();
        for (int i = 0; i < n; i++)
            c[i] = gti();
        dsu.init(n);
        for (int i = 0; i < n; i++)
            dsu.merge(i, loc[b[i]]);
        for (int i = 0; i < n; i++)
            if (c[i] != 0)
                vis[dsu.getfa(i)] = true;
        int ans = 1;
        for (int i = 0; i < n; i++)
            if (dsu.getfa(i) == i && !vis[i] && a[i] != b[i])
                ans = (ans << 1) % int(1e9 + 7);
        printf("%d\n", ans);
    }
	return 0;
}