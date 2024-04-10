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

const int N = 3031;
ll sl[N], sr[N];
int a[N];
int main(void)
{
    int n = gti(), k = gti();
    for (int i = 1; i <= n; i++)
    {
        a[i] = gti();
        sl[i] = sl[i - 1] + (a[i] ? a[i] : -k);
        sr[i] = sr[i - 1] + (a[i] ? a[i] : k);
    }
    ll ans = -2;
    for (int i = 0; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            ll l0 = sl[i], r0 = sr[i];
            ll l1 = sl[j] - sl[i], r1 = sr[j] - sr[i];
            ll l2 = sl[n] - sl[j], r2 = sr[n] - sr[j];
            if (l0 + l1 + l2 <= 0 && r0 + r1 + r2 >= 0)
                ans = std::max({ans, std::min(-l0 - l2, r1), std::min(r0 + r2, -l1)});
        }
    printf("%lld\n", ans + 1);
	return 0;
}