#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,q;

long long sy,a,b;
long long l[200005];
long long r[200005];
long long sum[200005];

long double calc(long double x,long double y,long double X)
{
	return X + (x - X) * sy / y;
}

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

long long x,y;
long double ans,p;

int main()
{
	sy = -read(),a = read(),b = read(),n = read();
	for (int i = 1;i <= n;i++)
	{
		l[i] = read(),r[i] = read();
		sum[i] = sum[i - 1] + r[i] - l[i];
	}
	q = read();
	for (int L,R,i = 1;i <= q;i++)
	{
		x = read(),y = read();
		ans = 0;
		if (l[n] * y + (x - l[n]) * sy < a * y)
			L = n + 1;
		else
		{
			int low = 1,high = n;
			while (low < high)
			{
				int mid = (low + high) >> 1;
				if (l[mid] * y + (x - l[mid]) * sy < a * y)
					low = mid + 1;
				else
					high = mid; 
			}
			L = low;
		}
		if (r[1] * y + (x - r[1]) * sy > b * y)
			R = 0;
		else
		{
			int low = 1,high = n;
			while (low < high)
			{
				int mid = (low + high + 1) >> 1;
				if (r[mid] * y + (x - r[mid]) * sy > b * y)
					high = mid - 1;
				else
					low = mid;
			}
			R = low;
		}
		if (L == R + 2)
		{
			printf("%.7lf\n",(double)(b - a));
			continue;
		}
		if (L <= R)
			ans = (long double)(sum[R] - sum[L - 1]) * (y - sy) / y;
		if (L > 1)
		{
			p = calc(x,y,r[L - 1]);
			if (p > a)
				ans += p - a;
		}
		if (R < n)
		{
			p = calc(x,y,l[R + 1]);
			if (p < b)
				ans += b - p;
		}
		printf("%.7lf\n",(double)ans);
	}
	return 0;
}