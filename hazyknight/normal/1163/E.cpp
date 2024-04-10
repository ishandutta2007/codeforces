#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

int n,tot;
int a[1 << 20];
int val[1 << 20];
int temp[1 << 20];

struct LinearBase
{
	int a[20],b[20],c[20];
	
	void insert(int v)
	{
		int tmp = v;
		for (int i = 19;i >= 0;i--)
			if (v >> i & 1)
			{
				if (!a[i])
				{
					a[i] = v;
					c[i] = tmp;
					for (int j = 19;j > i;j--)
						if (tmp >> j & 1)
							if (a[j])
							{
								tmp ^= a[j];
								b[i] ^= a[j];
							}
					return;
				}
				else
					v ^= a[i];
			}
	}
	
	void work()
	{
		for (int i = 19;i >= 0;i--)
			for (int j = i - 1;j >= 0;j--)
				if (a[i] >> j & 1)
				{
					a[i] ^= a[j];
					b[i] ^= a[j];
				}
	}
}lb;

void solve(int id)
{
	if (!id)
	{
		val[0] = 0;
		val[1] = 1;
		return;
	}
	solve(id - 1);
	for (int i = 0;i < (1 << id);i++)
		temp[i << 1] = temp[i << 1 | 1] = val[i];
	memcpy(val,temp,sizeof(val));
	for (int i = 0;i < (1 << (id + 1));i++)
		if (i % 4 == 1 || i % 4 == 2)
			val[i] |= (1 << id);
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++)
		lb.insert(a[i]);
	lb.work();
	for (int i = 1;i <= 19;i++)
	{
		if (!lb.a[i - 1])
			break;
		bool ok = 1;
		for (int j = 0;j < i;j++)
			if (lb.c[j] & ~((1 << i) - 1))
			{
				ok = 0;
				break;
			}
		if (ok)
			tot = max(tot,i);
	}
	printf("%d\n",tot);
	if (!tot)
	{
		printf("0\n");
		return 0;
	}
	solve(tot - 1);
	for (int i = 0;i < (1 << tot);i++)
	{
		int laz = 0;
		for (int j = 19;j >= 0;j--)
			if (val[i] >> j & 1)
				laz ^= lb.b[j];
		val[i] ^= laz;
		printf("%d ",val[i]);
	}
	printf("\n");
	return 0;
}