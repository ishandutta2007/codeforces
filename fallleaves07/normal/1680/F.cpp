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

struct rDSU
{
    struct T
    {
        int fa, dep;
    };
    std::vector<T> t;
    std::vector<std::pair<int, T>> rec;
    void init(int n)
    {
        t.resize(n + 1);
        for (int i = 0; i <= n; i++)
            t[i] = {i, 0};
    }
    int getTime(void) {return rec.size();}
    void reverse(int time)
    {
        while ((int)rec.size() > time)
            t[rec.back().first] = rec.back().second, rec.pop_back();
    }
    int getfa(int v)
    {
        if (t[v].fa == v) return v;
        return getfa(t[v].fa);
    }
    bool merge(int u, int v)
    {
        u = getfa(u), v = getfa(v);
        if (u == v) return false;
        if (t[u].dep > t[v].dep) std::swap(u, v);
        rec.push_back({v, t[v]});
        rec.push_back({u, t[u]});
        t[u].fa = v, t[v].dep = std::max(t[v].dep, t[u].dep + 1);
        return true;
    }
    bool same(int u, int v)
    {
        return getfa(u) == getfa(v);
    }
} dsu;

std::vector<std::pair<int, int>> edges;
int n, m;
bool merge(int u, int v)
{
    dsu.merge(u << 1, v << 1 | 1);
    dsu.merge(u << 1 | 1, v << 1);
    return !dsu.same(u << 1, u << 1 | 1);
}
bool solve(int l, int r)
{
    if (l == r)
    {
        int u = edges[l].first, v = edges[l].second;
        if (dsu.same(u << 1, v << 1 | 1) || dsu.same(u << 1, v << 1))
            dsu.merge(u << 1, 1);
        else dsu.merge(u << 1, 1), dsu.merge(v << 1, 1);
        return true;
    }
    int mid = (l + r) >> 1, t = dsu.getTime();
    bool tag = true;
    for (int i = mid + 1; i <= r; i++)
        if (!merge(edges[i].first, edges[i].second))
        {
            tag = false;
            break;
        }
    if (tag && solve(l, mid)) return true;
    dsu.reverse(t);
    tag = true, t = dsu.getTime();
    for (int i = l; i <= mid; i++)
        if (!merge(edges[i].first, edges[i].second))
        {
            tag = false;
            break;
        }
    if (tag && solve(mid + 1, r)) return true;
    dsu.reverse(t);
    return false;
}

const int N = 1e6 + 501;
int main(void)
{
    for (int T = gti(); T; T--)
    {
        n = gti(), m = gti();
        edges.resize(m + 1);
        dsu.init(n << 1 | 1);
        for (int i = 1; i <= m; i++)
            edges[i].first = gti(), edges[i].second = gti();
        if (!solve(1, m)) puts("NO");
        else
        {
            puts("YES");
            static char ans[N];
            for (int i = 1; i <= n; i++)
            {
                if (dsu.same(i << 1, 1)) ans[i] = '1';
                else if (dsu.same(i << 1 | 1, 1)) ans[i] = '0';
                else
                {
                    dsu.merge(i << 1, 1);
                    ans[i] = '1';
                }
            }
            ans[n + 1] = 0;
            puts(ans + 1);
        }
    }
	return 0;
}