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

char s[55][55];
bool check(int n, int m)
{
    int lid = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == 'R')
            {
                if (j < lid)
                    return false;
                if (lid == -1)
                    lid = j;
            }
        }
    return true;
}
int main(void)
{
    for (int T = gti(); T; T--)
    {
        int n = gti(), m = gti();
        for (int i = 0; i < n; i++)
            gts(s[i]);
        puts(check(n, m) ? "YES" : "NO");
    }
	return 0;
}