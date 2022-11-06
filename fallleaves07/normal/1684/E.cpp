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

struct SP
{
    std::priority_queue<int, std::vector<int>, std::less<int>> hSmall;
    std::priority_queue<int, std::vector<int>, std::greater<int>> hLarge;
    int sumSmall, sumLarge, k;
    void init(int k)
    {
        while (!hLarge.empty()) hLarge.pop();
        while (!hSmall.empty()) hSmall.pop();
        sumSmall = sumLarge = 0;
        this->k = k;
    }
    void limit(int k)
    {
        while (!hLarge.empty() && hLarge.top() + sumSmall <= k)
        {
            int x = hLarge.top();
            sumSmall += x, sumLarge -= x;
            hSmall.push(x), hLarge.pop();
        }
        while (!hSmall.empty() && sumSmall > k)
        {
            int x = hSmall.top();
            sumSmall -= x, sumLarge += x;
            hSmall.pop(), hLarge.push(x);
        }
    }
    void insert(int x)
    {
        int mid = 0;
        if (!hSmall.empty()) mid = hSmall.top();
        else if (!hLarge.empty()) mid = hLarge.top();
        if (x <= mid) sumSmall += x, hSmall.push(x);
        else sumLarge += x, hLarge.push(x);
        limit(k);
    }
} sp;

int main(void)
{
    for (int T = gti(); T; T--)
    {
        int n = gti(), k = gti();
        std::map<int, int> cnt;
        for (int i = 0; i < n; i++)
            ++cnt[gti()];
        sp.init(k);
        int cmex = 0;
        for (int i = 0; i <= n; i++)
            if (!cnt.count(i))
                ++cmex;
        for (auto [x, y] : cnt)
            if (x > n)
                sp.insert(y);
        int ans = n + 1;
        for (int i = n; i >= 0; i--)
        {
            if (!cnt.count(i)) --cmex;
            else sp.insert(cnt[i]);
            if (cmex <= k)
                ans = std::min(ans, (int)sp.hLarge.size());
        }
        printf("%d\n", ans);
    }
	return 0;
}