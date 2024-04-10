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

int n,b,q,tot;
int v[65];

ll l,r;
ll f[65][65][65];

int popcount(int v)
{
	return v ? popcount(v - (v & -v)) + 1 : 0;
}

ll solve(ll a,int b)
{
	if (!a)
		return 0;
	tot = 0;
	while (a)
	{
		v[tot++] = a % b;
		a /= b;
	}
	int mask = 0;
	ll res = 0;
	for (int i = tot - 1;i >= 0;i--)
	{
		for (int j = v[i] - 1;j >= (i == tot - 1);j--)
		{
			int cnt = popcount(mask ^ (1 << j));
			res += f[i][b - cnt][cnt];
		}
		mask ^= (1 << v[i]);
	}
	for (int i = tot - 1;i > 0;i--)
		res += (b - 1) * f[i - 1][b - 1][1];
	if (!mask)
		res++;
	return res;
}

int main()
{
	scanf("%d",&q);
	for (int i = 0;i <= 64;i++)
		f[0][i][0] = 1;
	for (int i = 1;i <= 64;i++)
		for (int j = 0;j <= 64;j++)
			for (int k = 0;j + k <= 64;k++)
			{
				if (j)
					f[i][j][k] += f[i - 1][j - 1][k + 1] * j;
				if (k)
					f[i][j][k] += f[i - 1][j + 1][k - 1] * k;
			}
	while (q--)
	{
		scanf("%d%lld%lld",&b,&l,&r);
		printf("%lld\n",solve(r,b) - solve(l - 1,b));
	}
	return 0;
}