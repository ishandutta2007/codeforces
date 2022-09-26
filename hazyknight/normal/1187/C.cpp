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

const int MAXN = 1005;

int n,m;
int t[MAXN];
int l[MAXN];
int r[MAXN];
int a[MAXN];

bool mark[MAXN];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= m;i++)
	{
		scanf("%d%d%d",&t[i],&l[i],&r[i]);
		if (t[i] == 1)
		{
			for (int j = l[i];j < r[i];j++)
				mark[j] = 1;
		}
	}
	for (int i = 1;i <= m;i++)
	{
		if (t[i] == 0)
		{
			bool ok = 0;
			for (int j = l[i];j < r[i];j++)
				if (!mark[j])
					ok = 1;
			if (!ok)
			{
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
	a[1] = 500000000;
	for (int i = 2;i <= n;i++)
		if (mark[i - 1])
			a[i] = a[i - 1] + 1;
		else
			a[i] = a[i - 1] - 1;
	for (int i = 1;i <= n;i++)
		printf("%d ",a[i]);
	puts("");
	return 0;
}