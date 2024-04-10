#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>

using namespace std;

inline char gc()
{
	static char buf[1048576],*p1 = buf,*p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,1048576,stdin),p1 == p2) ? EOF : *p1++;
}

inline void read(int &v)
{
	v = 0;
	char c = gc();
	while (c < '0' || c > '9')
		c = gc();
	while (c >= '0' && c <= '9')
	{
		v = v * 10 + c - '0';
		c = gc();
	}
}

const int MAXN = 500005;
const int SIZE = 400;
const int CNT = 1250;

struct Base
{
	int b[20];
	void insert(int v)
	{
		for (int i = 19;v && i >= 0;i--)
			if (v >> i & 1)
			{
				if (!b[i])
				{
					b[i] = v;
					return;
				}
				v ^= b[i];
			}
	}
};

Base merge(const Base &a,const Base &b)
{
	Base res = a;
	for (int i = 19;i >= 0;i--)
		if (b.b[i])
			res.insert(b.b[i]);
	return res;
}

int n,N,q;
int a[MAXN];

Base w[CNT];
Base W[CNT][CNT];
Base pre[CNT][SIZE];
Base suf[CNT][SIZE];
Base v[CNT][SIZE / 20];
Base V[CNT][SIZE / 20][SIZE / 20];

int main()
{
	read(n);
	N = (n - 1) / SIZE + 1;
	for (int i = 0;i < n;i++)
	{
		read(a[i]);
		w[i / SIZE].insert(a[i]);
	}
	for (int i = 0;i < N;i++)
	{
		W[i][i] = w[i];
		for (int j = i + 1;j < N;j++)
			W[i][j] = merge(W[i][j - 1],w[j]);
	}
	for (int i = 0;i < N;i++)
	{
		pre[i][0].insert(a[i * SIZE]);
		for (int j = 1;j < SIZE;j++)
		{
			pre[i][j] = pre[i][j - 1];
			pre[i][j].insert(a[i * SIZE + j]);
		}
		suf[i][SIZE - 1].insert(a[i * SIZE + SIZE - 1]);
		for (int j = SIZE - 2;j >= 0;j--)
		{
			suf[i][j] = suf[i][j + 1];
			suf[i][j].insert(a[i * SIZE + j]);
		}
	}
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < 20;j++)
			for (int k = 0;k < 20;k++)
				v[i][j].insert(a[i * SIZE + j * 20 + k]);
		for (int j = 0;j < 20;j++)
		{
			V[i][j][j] = v[i][j];
			for (int k = j + 1;k < 20;k++)
				V[i][j][k] = merge(V[i][j][k - 1],v[i][k]);
		}
	}
	read(q);
	for (int l,r,i = 1;i <= q;i++)
	{
		read(l),read(r);
		l--,r--;
		Base res;
		int L = l / SIZE,R = r / SIZE;
		if (L == R)
		{
			int L1 = (l - L * SIZE) / 20,R1 = (r - R * SIZE) / 20;
			if (L1 == R1)
			{
				memset(res.b,0,sizeof(res.b));
				for (int j = l;j <= r;j++)
					res.insert(a[j]);
			}
			else
			{
				res = V[L][L1 + 1][R1 - 1];
				for (int j = l;j < L * SIZE + (L1 + 1) * 20;j++)
					res.insert(a[j]);
				for (int j = R * SIZE + R1 * 20;j <= r;j++)
					res.insert(a[j]);
			}
		}
		else
			res = merge(merge(suf[L][l - L * SIZE],W[L + 1][R - 1]),pre[R][r - R * SIZE]);
		int ans = 0;
		for (int j = 19;j >= 0;j--)
			ans = max(ans,ans ^ res.b[j]);
		printf("%d\n",ans);
	}
	return 0;
}