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

typedef long long ll;

inline char gc()
{
	static char buf[1048576],*p1 = buf,*p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,1048576,stdin),p1 == p2) ? EOF : *p1++;
}

inline void read(int &v)
{
	v = 0;
	char c = gc();
	while ((c < '0' || c > '9') && c != '+' && c != '-')
		c = gc();
	if (c == '+')
	{
		v = 0;
		return;
	}
	if (c == '-')
	{
		v = 1;
		return;
	}
	while (c >= '0' && c <= '9')
	{
		v = v * 10 + c - '0';
		c = gc();
	}
}

const int MAXN = 500005;

struct Set
{
	priority_queue<int> Q1,Q2;
	void insert(int v)
	{
		Q1.push(-v);
	}
	void erase(int v)
	{
		Q2.push(-v);
	}
	void flush()
	{
		while (!Q2.empty() && Q1.top() == Q2.top())
		{
			Q1.pop();
			Q2.pop();
		}
	}
	int MIN()
	{
		flush();
		return -Q1.top();
	}
}S[MAXN];

int q,ans;

ll sum[MAXN];

int main()
{
	read(q);
	for (int tp,v,i = 1;i <= q;i++)
	{
		read(tp),read(v);
		int bel = 0;
		for (;(1 << bel) <= v;bel++);
		bel--;
		if (!tp)
		{
			ans++;
			sum[bel] += v;
			S[bel].insert(v);
		}
		else
		{
			ans--;
			sum[bel] -= v;
			S[bel].erase(v);
		}
		ll presum = 0;
		int fat = 0;
		for (int j = 0;j < 30;j++)
		{
			if (!sum[j])
				continue;
			if (presum * 2 < S[j].MIN())
				fat++;
			presum += sum[j];
		}
		printf("%d\n",ans - fat);
	}
	return 0;
}