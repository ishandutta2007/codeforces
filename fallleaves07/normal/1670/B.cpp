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
int main(void)
{
    for (int T = gti(); T; T--)
    {
        static char s[N];
        int n = gti();
        gts(s);
        int k = gti();
        std::set<char> st;
        for (int i = 0; i < k; i++)
        {
            static char ch[10];
            gts(ch);
            st.insert(ch[0]);
        }
        int lst = -1, ans = 0;
        for (int i = 0; i < n; i++)
            if (st.count(s[i]))
            {
                if (lst == -1)
                    ans = std::max(ans, i - lst - 1);
                else ans = std::max(ans, i - lst);
                lst = i;
            }
        printf("%d\n", ans);
    }
	return 0;
}