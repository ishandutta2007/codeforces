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
        std::vector<int> a(n);
        for (int i = 0; i < n; i++)
            a[i] = gti();
        auto solve = [](std::vector<int> &a)
        {
            int n = a.size();
            std::vector<ll> cntr(n + 1);
            ll ans = 0;
            for (int i = 1; i < n - 1; i++)
            {
                std::fill(cntr.begin(), cntr.end(), 0);
                int cnt = 0;
                for (int j = n - 1; j > i; j--)
                    if (a[j] < a[i])
                    {
                        cntr[a[j]] += cnt;
                        ++cnt;
                    }
                for (int j = a[i] - 1; j >= 0; j--)
                    cntr[j] += cntr[j + 1];
                for (int j = 0; j < i; j++)
                    if (a[j] < a[i])
                        ans += cntr[a[j] + 1];
            }
            return ans;
        };
        ll ans = solve(a);
        std::reverse(a.begin(), a.end());
        ans += solve(a);
        printf("%lld\n", ans);
    }
	return 0;
}