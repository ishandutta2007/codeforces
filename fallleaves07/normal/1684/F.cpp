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
		int n = gti(), m = gti();
		std::vector<std::vector<int>> idx;
		std::vector<int> a(n + 1), lst(n + 1), nxt(n + 1), lstv(n + 1), nxtv(n + 1);
		for (int i = 1; i <= n; i++)
			a[i] = gti();
		
		{
			std::map<int, int> id;
			for (int i = 1; i <= n; i++)
				id[a[i]] = 0;
			int rk = 0;
			for (auto &p : id)
				p.second = ++rk;
			for (int i = 1; i <= n; i++)
				a[i] = id[a[i]];
			idx.resize(rk + 1);
			for (int i = 1; i <= n; i++)
				idx[a[i]].push_back(i);
		}

		for (int i = 1; i <= n; i++)
		{
			lst[i] = lstv[a[i]];
			lstv[a[i]] = i;
		}
		std::fill(nxtv.begin(), nxtv.end(), n + 1);
		for (int i = n; i >= 1; i--)
		{
			nxt[i] = nxtv[a[i]];
			nxtv[a[i]] = i;
		}
		std::vector<int> prer(n + 1), sufl(n + 1);
		int r = n;
		for (int i = n; i >= 1; i--)
		{
			r = std::min(r, nxt[i] - 1);
			prer[i] = r;
		}
		int l = 1;
		for (int i = 1; i <= n; i++)
		{
			l = std::max(l, lst[i] + 1);
			sufl[i] = l;
		}
		std::vector<std::pair<int, int>> seg;
		std::vector<int> lft(n + 1);
		std::fill(lft.begin(), lft.end(), n + 1);
		seg.reserve(m);
		l = n + 1, r = 0;
		for (int i = 0; i < m; i++)
		{
			int il = gti(), ir = gti();
			if (prer[il] >= ir) continue;
			l = std::min(l, prer[il] + 1);
			r = std::max(r, sufl[ir] - 1);
			seg.push_back({il, ir});
			lft[ir] = std::min(lft[ir], il);
		}
		int lx = n + 1, ans = n + 1;
		for (int i = n; i >= r; i--)
		{
			ans = std::min(ans, i - l + 1);
			lx = std::min(lx, lft[i]);
			auto lp = std::lower_bound(idx[a[i]].begin(), idx[a[i]].end(), lx);
			if (lp != idx[a[i]].end()) l = std::min(l, *lp);
		}
		printf("%d\n", std::max(ans, 0));
	}
	return 0;
}