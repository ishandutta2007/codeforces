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
        const int N = 2e5 + 501;
        static char s[N];
        int n = gti();
        gts(s);
        int lst = 0;
        std::vector<int> tag;
        for (int i = 1; i <= n; i++)
            if (s[i] != s[i - 1])
            {
                tag.push_back(i - lst);
                lst = i;
            }
        int ans = 0;
        lst = -1;
        for (int i = 0; i < (int)tag.size(); i++)
            if (tag[i] & 1)
            {
                if (lst == -1)
                    lst = i;
                else
                {
                    ans += i - lst;
                    lst = -1;
                }
            }
        printf("%d\n", ans);
    }
	return 0;
}