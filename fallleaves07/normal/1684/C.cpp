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

bool solve(void)
{
    int n = gti(), m = gti();
    std::vector<std::vector<int>> a;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        a[i].resize(m);
        for (int j = 0; j < m; j++)
            a[i][j] = gti();
    }
    std::vector<int> id(m), tag(m);
    for (int i = 0; i < m; i++)
        id[i] = i;
    for (int i = 0; i < n; i++)
        std::stable_sort(id.begin(), id.end(), [&](int x, int y){return a[i][x] < a[i][y];});
    for (int d = 1; d < m; d++)
    {
        int csmall = 0, cequal = 0;
        for (int j = 0; j < n; j++)
            if (a[j][id[d]] > a[j][id[d - 1]])
                ++csmall;
            else if (a[j][id[d]] == a[j][id[d - 1]])
                ++cequal;
        if (csmall + cequal != n) return false;
        if (csmall == 0) tag[id[d]] = tag[id[d - 1]];
        else tag[id[d]] = tag[id[d - 1]] + 1;
    }
    std::vector<int> rtag(tag), idx;
    std::sort(rtag.begin(), rtag.end());
    for (int i = 0; i < m; i++)
        if (tag[i] != rtag[i])
            idx.push_back(i);
    if (idx.size() > 2) return false;
    if (idx.empty()) idx.push_back(0);
    printf("%d %d\n", idx.front() + 1, idx.back() + 1);
    return true;
}
int main(void)
{
    for (int T = gti(); T; T--)
        if (!solve())
            puts("-1");
    return 0;
}