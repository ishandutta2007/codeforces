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

const int M = 1e9 + 7;
int mod(int val)
{
	return (val < 0) ? (val + M) : ((val >= M) ? (val - M) : val);
}
void inc(int &v, ll val)
{
	v = (v + val) % M;
}
void inc(int &v, int val)
{
	v = mod(v + val);
}

int c[1021][1021];
void init(int n)
{
	c[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= n; j++)
			c[i][j] = mod(c[i - 1][j - 1] + c[i - 1][j]);
	}
}
int f[71][2021][2];
int solve(int n, ll r, ll z)
{
	memset(f, 0, sizeof(f));
	int mxl = 0;
	for (int i = (z & 1); i <= n; i += 2)
	{
		mxl = std::max(mxl, i >> 1);
		inc(f[0][i >> 1][(i & 1) < (r & 1)], c[n][i]);
	}
	for (int i = 1; i <= 60; i++)
	{
		int nxl = 0;
		for (int j = 0; j <= mxl; j++)
			for (int k = ((z >> i) & 1); k <= n; k += 2)
			{
				nxl = std::max(nxl, (j + k) >> 1);
				int zb = (j + k) & 1, rb = (r >> i) & 1;
				int v0 = 1ll * f[i - 1][j][0] * c[n][k] % M;
				int v1 = 1ll * f[i - 1][j][1] * c[n][k] % M;
				if (zb < rb)
				{
					inc(f[i][(j + k) >> 1][1], v0);
					inc(f[i][(j + k) >> 1][1], v1);
				}
				else if (zb == rb)
				{
					inc(f[i][(j + k) >> 1][0], v0);
					inc(f[i][(j + k) >> 1][1], v1);
				}
				else if (zb > rb)
				{
					inc(f[i][(j + k) >> 1][0], v0);
					inc(f[i][(j + k) >> 1][0], v1);
				}
			}
		mxl = nxl;
	}
	return f[60][0][1];
}
int main(void)
{
	int n = gti();
	init(n);
	ll l = gti(), r = gti(), z = gti();
	printf("%d\n", mod(solve(n, r + 1, z) - solve(n, l, z)));
	return 0;
}