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
        int n = gti(), m = gti(), l = n * m;
        const int N = 1e6 + 501;
        static char s[N];
        gts(s);
        std::vector<bool> tag(m);
        std::vector<int> sum(m);
        int ans = 0, len = m - 1;
        auto update = [&](int l, int r)
        {
            //printf("[%d %d]\n", l, r);
            if (r < 0) return;
            if (r - l + 1 >= m)
            {
                for (int i = r + 1; i <= r + m; i++)
                    sum[i % m] += (i - l + 1) / m - ((i - r - 1) / m + 1);
            }
        };
        for (int i = 0; i < l; i++)
        {
            if (s[i] == '1')
            {
                if (!tag[i % m])
                    tag[i % m] = true, ans++;
                if (len)
                {
                    update(i - len, i - 1);
                    len = 0;
                }
            }
            else
                ++len;
            printf("%d%c", ans + (i / m + 1 - sum[i % m] - len / m), " \n"[i == l - 1]);
        }
    }
	return 0;
}