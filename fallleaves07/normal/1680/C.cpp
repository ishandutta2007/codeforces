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
char s[N];
int cnt[N][2];
int main(void)
{
    for (int T = gti(); T; T--)
    {
        int n = gts(s + 1);
        for (int i = 1; i <= n; i++)
        {
            cnt[i][0] = cnt[i - 1][0] + (s[i] == '0');
            cnt[i][1] = cnt[i - 1][1] + (s[i] == '1');
        }
        int tot = cnt[n][1], l = 0, ans = n * 2;
        for (int i = 1; i <= n; i++)
        {
            while (l < i && cnt[i][0] - cnt[l][0] > tot - (cnt[i][1] - cnt[l][1]))
                ++l;
            while (l > 0 && cnt[i][0] - cnt[l][0] < tot - (cnt[i][1] - cnt[l][1]))
                --l;
            if (cnt[i][0] - cnt[l][0] == tot - (cnt[i][1] - cnt[l][1]))
                ans = std::min(ans, cnt[i][0] - cnt[l][0]);
        }
        printf("%d\n", ans);
    }
	return 0;
}