#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

inline char gc()
{
	static char buf[131072],*p1 = buf,*p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,131072,stdin),p1 == p2) ? EOF : *p1++;
}

inline int read()
{
	char ch = gc();
	int sum = 0;
	while (!(ch >= '0' && ch <= '9'))
		ch = gc();
	while (ch >= '0' && ch <= '9')
		sum = sum * 10 + ch - '0',ch = gc();
	return sum;
}

inline int bin_read()
{
	char ch = gc();
	int sum = 0;
	while (!(ch >= '0' && ch <= '9'))
		ch = gc();
	while (ch >= '0' && ch <= '9')
		sum = sum * 2 + ch - '0',ch = gc();
	return sum;
}

int n,m,q;
int w[15];
int val[1 << 12];
int cnt[1 << 12];
int wu[1 << 12][1 << 12];
int ans[1 << 12][1205];

int main()
{
	ios::sync_with_stdio(false);
	n = read(),m = read(),q = read();
	for (int i = n - 1;i >= 0;i--)
		w[i] = read();
	for (int i = 0;i < (1 << n);i++)
		for (int j = 0;j < n;j++)
			if (~i & (1 << j))
				val[i] += w[j];
	for (int i = 0;i < (1 << n);i++)
		for (int j = 0;j < (1 << n);j++)
			wu[i][j] = val[i ^ j];
	for (int i = 1;i <= m;i++)
		cnt[bin_read()]++;
	for (int i = 0;i < (1 << n);i++)
	{
		for (int j = 0;j < (1 << n);j++)
			ans[i][wu[i][j]] += cnt[j];
		for (int j = 1;j <= 100;j++)
			ans[i][j] += ans[i][j - 1];
	}
	for (int i = 1;i <= q;i++)
	{
		int s = bin_read();
		cout << ans[s][read()] << endl;
	}
	return 0;
}