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

int main(void)
{
    int n = gti(), m = gti();
    std::vector<int> p(n + 1), rk(n + 1), deg(m + 1);
    std::vector<std::vector<std::pair<int, int>>> to(n + 1);
    std::vector<std::vector<int>> edges(m + 1);
    std::vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++) p[i] = gti();
    for (int i = 1; i <= m; i++)
    {
        int u = gti(), v = gti();
        to[u].push_back({v, i});
        to[v].push_back({u, i});
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            std::vector<int> cir;
            for (int v = i; !vis[v]; v = p[v])
                cir.push_back(v), vis[v] = true;
            for (int i = 0; i < (int)cir.size(); i++)
                rk[cir[i]] = i;
            for (auto v : cir)
            {
                auto getrk = [&](int id)
                {
                    int r = rk[id];
                    if (r < rk[v])
                        r += (int)cir.size();
                    return r;
                };
                std::sort(to[v].begin(), to[v].end(),
                          [&](std::pair<int, int> a, std::pair<int, int> b)
                          {
                              return getrk(a.first) < getrk(b.first);
                          });
                for (int i = 1; i < (int)to[v].size(); i++)
                    edges[to[v][i - 1].second].push_back(to[v][i].second), ++deg[to[v][i].second];
            }
        }
    std::queue<int> que;
    for (int i = 1; i <= m; i++)
        if (deg[i] == 0)
            que.push(i);
    while (!que.empty())
    {
        int v = que.front();
        que.pop();
        for (auto u : edges[v])
            if (!--deg[u])
                que.push(u);
        printf("%d ", v);
    }
    puts("");
    return 0;
}