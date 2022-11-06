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
    for (int T = gti(); T; T--)
    {
        int n = gti();
        std::vector<int> id(n), to(n + 1), vis(n + 1);
        for (int i = 0; i < n; i++)
            id[i] = gti();
        for (int i = 0; i < n; i++)
            to[id[i]] = gti();
        std::vector<int> cirs;
        int prelen = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                int clen = 0;
                for (int j = i; !vis[j]; j = to[j])
                    vis[j] = true, clen++;
                if (clen & 1) ++prelen, --clen;
                if (clen) cirs.push_back(clen);
            }
        }
        std::sort(cirs.begin(), cirs.end());
        std::reverse(cirs.begin(), cirs.end());
        auto calc = [](int prelen, int l)
        {
            int r = prelen + l - 1, c = l - 1;
            ll ret = (r + (r - c + 1ll)) * c / 2;
            return ret + prelen + (l >> 1);
        };
        ll ans = 0;
        for (auto l : cirs)
        {
            ans += calc(prelen, l);
            prelen += l;
        }
        printf("%lld\n", ans);
    }
	return 0;
}