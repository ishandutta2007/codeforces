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

const int MAXN = 1000005;

int n,w,m,top;
int a[MAXN];
int l[MAXN];
int r[MAXN];
int S[MAXN];

ll sum[MAXN];

void modify(int p,int v)
{
	while (p <= w)
	{
		sum[p] += v;
		p += p & -p;
	}
}

ll query(int p)
{
	ll res = 0;
	while (p >= 1)
	{
		res += sum[p];
		p -= p & -p;
	}
	return res;
}

int main()
{
	scanf("%d%d",&n,&w);
	w += 2;
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&m);
		m += 2;
		a[1] = a[m] = 0;
		for (int j = 2;j <= m - 1;j++)
			scanf("%d",&a[j]);
		top = 0;
		for (int j = 1;j <= m;j++)
		{
			while (top >= 1 && a[S[top]] <= a[j])
			{
				r[S[top]] = j - 1;
				top--;
			}
			S[++top] = j;
		}
		while (top >= 1)
		{
			r[S[top]] = w - (m - S[top]);
			top--;
		}
		for (int j = m;j >= 1;j--)
		{
			while (top >= 1 && a[S[top]] < a[j])
			{
				l[S[top]] = w - (m - j) + 1;
				top--;
			}
			S[++top] = j;
		}
		while (top >= 1)
		{
			l[S[top]] = S[top];
			top--;
		}
		for (int j = 1;j <= m;j++)
		{
			l[j] = max(l[j],j);
			r[j] = min(r[j],w - (m - j));
		}
		for (int j = 1;j <= m;j++)
			if (l[j] <= r[j])
			{
				modify(l[j],a[j]);
				modify(r[j] + 1,-a[j]);
			}
	}
	for (int i = 2;i <= w - 1;i++)
		printf("%lld ",query(i));
	printf("\n");
	return 0;
}