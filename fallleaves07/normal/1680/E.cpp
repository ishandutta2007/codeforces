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

const int N = 2e5 + 501, inf = 0x3f3f3f3f;
char s[2][N];
int f[N][4];
int main(void)
{
    for (int T = gti(); T; T--)
    {
        int n = gti();
        gts(s[0]), gts(s[1]);
        int l = -1, r = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[0][i] == '.' && s[1][i] == '.') continue;
            if (l == -1) l = i;
            r = i;
        }
        for (int i = 0; i < 4; i++) f[l][i] = inf;
        if (s[0][l] == '*' && s[1][l] == '*')
            f[l][3] = 0, f[l][2] = f[l][1] = 1;
        else if (s[0][l] == '*')
            f[l][2] = 1, f[l][1] = 0;
        else if (s[1][l] == '*')
            f[l][2] = 0, f[l][1] = 1;
        for (int i = l + 1; i <= r; i++)
        {
            if (s[0][i] == '*' && s[1][i] == '*')
            {
                f[i][3] = std::min({f[i - 1][1] + 1, f[i - 1][2] + 1, f[i - 1][3] + 2});
                f[i][2] = std::min({f[i - 1][1] + 2, f[i - 1][2] + 2, f[i - 1][3] + 3});
                f[i][1] = std::min({f[i - 1][1] + 2, f[i - 1][2] + 2, f[i - 1][3] + 3});
            }
            else if (s[0][i] == '*')
            {
                f[i][3] = std::min({f[i - 1][1] + 2, f[i - 1][2] + 1, f[i - 1][3] + 2});
                f[i][2] = std::min({f[i - 1][1] + 2, f[i - 1][2] + 2, f[i - 1][3] + 3});
                f[i][1] = std::min({f[i - 1][1] + 1, f[i - 1][2] + 2, f[i - 1][3] + 2});
            }
            else if (s[1][i] == '*')
            {
                f[i][3] = std::min({f[i - 1][1] + 2, f[i - 1][2] + 1, f[i - 1][3] + 2});
                f[i][2] = std::min({f[i - 1][1] + 2, f[i - 1][2] + 1, f[i - 1][3] + 2});
                f[i][1] = std::min({f[i - 1][1] + 2, f[i - 1][2] + 2, f[i - 1][3] + 3});
            }
            else
            {
                f[i][3] = f[i - 1][3] + 2;
                f[i][2] = std::min({f[i - 1][1] + 2, f[i - 1][2] + 1, f[i - 1][3] + 2});
                f[i][1] = std::min({f[i - 1][1] + 1, f[i - 1][2] + 2, f[i - 1][3] + 2});
            }
        }
        printf("%d\n", std::min(f[r][1], f[r][2]));
    }
	return 0;
}