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
        int sgn = 0;
        for (int i = 0; i < n; i++)
        {
            a[i] = gti();
            if (a[i] < 0) ++sgn;
        }
        for (int i = 0; i < sgn; i++)
            a[i] = -std::abs(a[i]);
        for (int i = sgn;  i < n; i++)
            a[i] = std::abs(a[i]);
        bool ans = true;
        for (int i = 1; i < n; i++)
            if (a[i - 1] > a[i])
                ans = false;
        puts(ans ? "YES" : "NO");
    }
    return 0;
}