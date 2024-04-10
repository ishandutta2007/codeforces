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

const int MAXN = 200005;

int q,n,tot;
int a[MAXN];
int b[MAXN];

int force()
{
	int res = b[tot];
	for (int i = 1;i <= tot;i++)
		for (int j = tot;j > i;j--)
			if (b[j] % b[i] != 0)
			{
				res = max(res,b[i] + b[j]);
				break;
			}
	return res;
}

int solve()
{
	if (n == 1)
		return a[1];
	if (n == 2)
		return a[2] % a[1] ? a[1] + a[2] : a[2];
	if (a[n - 2] > a[n] / 2)
		return a[n - 2] + a[n - 1] + a[n];
	int res = 0;
	if (a[n - 1] <= a[n] / 2)
	{
		tot = 0;
		for (int i = 1;i < n;i++)
			if (a[n] % a[i])
				b[++tot] = a[i];
		res = force() + a[n];
		n--;
		return max(res,solve());
	}
	res = a[n - 1] + a[n];
	for (int i = n - 2;i >= 1;i--)
		if (a[n] % a[i] && a[n - 1] % a[i])
		{
			res = a[i] + a[n - 1] + a[n];
			break;
		}
	tot = 0;
	for (int i = 1;i <= n - 2;i++)
		if (a[n - 1] % a[i])
			b[++tot] = a[i];
	res = max(res,force() + a[n - 1]);
	tot = 0;
	for (int i = 1;i <= n - 2;i++)
		if (a[n] % a[i])
			b[++tot] = a[i];
	res = max(res,force() + a[n]);
	n -= 2;
	return max(res,solve());
}

int main()
{
	scanf("%d",&q);
	while (q--)
	{
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
			scanf("%d",&a[i]);
		sort(a + 1,a + n + 1);
		n = unique(a + 1,a + n + 1) - a - 1;
		printf("%d\n",solve());
	}
	return 0;
}