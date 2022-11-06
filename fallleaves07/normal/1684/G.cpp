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

namespace Maxflow
{
    const int inf = 0x3f3f3f3f;
    struct Edge
    {
        int to, f;
    };
    std::vector<Edge> e;
    std::vector<std::vector<int>> g;
    std::vector<int> cur, gap, dis;
    int S, T, tot;
    void init(int _s, int _t, int _tot)
    {
        S = _s, T = _t, tot = _tot;
        cur.resize(tot + 1), gap.resize(tot + 1), g.resize(tot + 1), dis.resize(tot + 1);
    }
    void addedge(int a, int b, int f)
    {
        g[a].push_back(e.size()), e.push_back({b, f});
        g[b].push_back(e.size()), e.push_back({a, 0});
    }
    void prework(void)
    {
        std::fill(dis.begin(), dis.end(), -1);
        std::queue<int> que;
        que.push(T), dis[T] = 0;
        while (!que.empty())
        {
            int v = que.front();
            que.pop();
            for (auto i : g[v])
                if (e[i ^ 1].f && dis[e[i].to] == -1)
                {
                    dis[e[i].to] = dis[v] + 1;
                    que.push(e[i].to);
                }
        }
        if (dis[S] == -1) dis[S] = tot;
        for (int i = 1; i <= tot; i++)
            if (dis[i] != -1)
                ++gap[dis[i]];
    }
    int isap(int v, int flow)
    {
        if (v == T) return flow;
        int ref = flow;
        for (int &c = cur[v]; c < (int)g[v].size(); c++)
        {
            int i = g[v][c];
            if (e[i].f && dis[e[i].to] == dis[v] - 1)
            {
                int fl = isap(e[i].to, std::min(ref, e[i].f));
                ref -= fl, e[i].f -= fl, e[i ^ 1].f += fl;
                if (ref == 0 || dis[S] == tot) return flow - ref;
            }
        }
        if (!--gap[dis[v]++]) dis[S] = tot;
        ++gap[dis[v]], cur[v] = 0;
        return flow - ref;
    }
    int maxflow(void)
    {
        int ans = 0;
        for (prework(); dis[S] < tot; ans += isap(S, inf));
        return ans;
    }
}

int main(void)
{
    auto solve = [&](void) -> bool
    {
        int n = gti(), m = gti();
        std::vector<int> t(n + 1);
        for (int i = 1; i <= n; i++)
            t[i] = gti();
        using namespace Maxflow;
        init(n + 1, n + 2, n + 2);
        for (int i = 1; i <= n; i++)
            if (3ll * t[i] > m)
            {
                addedge(S, i, 1);
                for (int j = 1; j <= n; j++)
                    if (2ll * t[i] + t[j] <= m && t[i] % t[j] == 0)
                        addedge(i, j, 1);
            }
            else
                addedge(i, T, 1);
        maxflow();
        std::vector<std::pair<int, int>> ans;
        for (int i = 1; i <= n; i++)
            for (int ex : g[i])
            {
                if (3ll * t[i] > m)
                {
                    if (e[ex].to == S && e[ex].f != 1)
                        return false;
                    if (e[ex].to != S && e[ex].f == 0)
                        ans.push_back({t[i] * 2ll + t[e[ex].to], t[i] + t[e[ex].to]});
                }
                else if (e[ex].to == T && e[ex].f == 1)
                    ans.push_back({3ll * t[i], 2ll * t[i]});
            }
        printf("%ld\n", ans.size());
        for (auto [u, v] : ans)
            printf("%d %d\n", u, v);
        return true;
    };
    if (!solve())
        puts("-1");
    return 0;
}