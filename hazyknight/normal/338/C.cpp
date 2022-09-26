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

typedef long long ll;

const int MAXN = 8;

int n,ans = 1e9;
int sz[MAXN];
int f[MAXN][1 << MAXN];

ll a[MAXN];

int popcount(int v)
{
	return v ? popcount(v - (v & -v)) + 1 : 0;
}

int main()
{
	scanf("%d",&n);
	for (int i = 0;i < n;i++)
		scanf("%lld",&a[i]);
	sort(a,a + n);
	n = unique(a,a + n) - a;
	for (int i = 0;i < n;i++)
	{
		ll v = a[i];
		for (ll j = 2;j * j <= v;j++)
			while (v % j == 0)
			{
				sz[i]++;
				v /= j;
			}
		if (v > 1)
			sz[i]++;
	}
	for (int i = 0;i < n;i++)
		for (int j = 0;j < (1 << (i + 1));j++)
			f[i][j] = 1e9;
	f[0][1] = sz[0] + (sz[0] > 1);
	for (int i = 0;i < n - 1;i++)
		for (int j = 1;j < (1 << (i + 1));j++)
			for (int k = j;;k = (k - 1) & j)
			{
				ll v = a[i + 1];
				int SZ = sz[i + 1];
				bool ok = 1;
				for (int l = 0;l <= i;l++)
					if (k >> l & 1)
					{
						SZ -= sz[l];
						if (v % a[l] != 0)
						{
							ok = 0;
							break;
						}
						v /= a[l];
					}
				if (!ok)
					continue;
				if (!k)
					f[i + 1][j ^ k | (1 << (i + 1))] = min(f[i + 1][j ^ k | (1 << (i + 1))],f[i][j] + SZ + (SZ > 1));
				else
					f[i + 1][j ^ k | (1 << (i + 1))] = min(f[i + 1][j ^ k | (1 << (i + 1))],f[i][j] + SZ + 1);
				if (!k)
					break;
			}
	for (int i = 1;i < (1 << n);i++)
	{
		if (popcount(i) == 1)
			ans = min(ans,f[n - 1][i]);
		else
			ans = min(ans,f[n - 1][i] + 1);
	}
	printf("%d\n",ans);
	return 0;
}