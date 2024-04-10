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

const int MAXN = 105;
const int MAXM = 305;

int n,tot,ans;
int a[MAXN];
int l[MAXN];
int r[MAXN];
int x[MAXM];
int gl[MAXN][MAXN][MAXM];
int gr[MAXN][MAXN][MAXM];
int f[MAXN][MAXM];

int getx(int v)
{
	for (int i = 1;i <= tot;i++)
		if (v == x[i])
			return i;
	return 0;
}

void ok(int i,int j,int k,int l)
{
	gl[i][j][l] = min(gl[i][j][l],k);
	gr[i][j][k] = max(gr[i][j][k],l);
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d%d",&a[i],&l[i]);
		x[++tot] = a[i] - l[i];
		x[++tot] = a[i];
		x[++tot] = a[i] + l[i];
	}
	sort(x + 1,x + tot + 1);
	tot = unique(x + 1,x + tot + 1) - x - 1;
	for (int i = 1;i <= n;i++)
		for (int j = i + 1;j <= n;j++)
			if (a[i] > a[j])
			{
				swap(a[i],a[j]);
				swap(l[i],l[j]);
			}
	for (int i = 1;i <= n;i++)
	{
		r[i] = getx(a[i] + l[i]);
		l[i] = getx(a[i] - l[i]);
		a[i] = getx(a[i]);
	}
	for (int i = 1;i <= n;i++)
		for (int j = i;j <= n;j++)
			for (int k = 1;k <= tot;k++)
				gl[i][j][k] = tot + 1;
	for (int i = 1;i <= n;i++)
	{
		ok(i,i,l[i],a[i]);
		ok(i,i,a[i],r[i]);
	}
	for (int len = 1;len < n;len++)
	{
		for (int i = 1,j = len;j <= n;i++,j++)
		{
			for (int k = 2;k <= tot;k++)
				gr[i][j][k] = max(gr[i][j][k],gr[i][j][k - 1]);
			for (int k = tot - 1;k >= 1;k--)
				gl[i][j][k] = min(gl[i][j][k],gl[i][j][k + 1]);
		}
		for (int i = 1,j = len;j <= n;i++,j++)
			for (int k = 1;k <= tot;k++)
			{
				if (i > 1)
				{
					ok(i - 1,j,gl[i][j][k],k);
					ok(i - 1,j,k,gr[i][j][k]);
				}
				if (j < n)
				{
					ok(i,j + 1,gl[i][j][k],k);
					ok(i,j + 1,k,gr[i][j][k]);
				}
				for (int l = i - 1;l >= 1;l--)
				{
					if (gl[i][j][k] <= k && gl[l][i - 1][gl[i][j][k]] <= gl[i][j][k])
						ok(l,j,gl[l][i - 1][gl[i][j][k]],k);
					if (gr[i][j][k] >= k && gl[l][i - 1][k] <= k)
						ok(l,j,gl[l][i - 1][k],gr[i][j][k]);
					if (gr[i][j][k] >= k && gr[l][i - 1][gr[i][j][k]] >= gr[i][j][k])
						ok(l,j,k,gr[l][i - 1][gr[i][j][k]]);
					if (gl[i][j][k] <= k && gr[l][i - 1][k] >= k)
						ok(l,j,gl[i][j][k],gr[l][i - 1][k]);
				}
				for (int l = j + 1;l <= n;l++)
				{
					if (gl[i][j][k] <= k && gl[j + 1][l][gl[i][j][k]] <= gl[i][j][k])
						ok(i,l,gl[j + 1][l][gl[i][j][k]],k);
					if (gr[i][j][k] >= k && gl[j + 1][l][k] <= k)
						ok(i,l,gl[j + 1][l][k],gr[i][j][k]);
					if (gr[i][j][k] >= k && gr[j + 1][l][gr[i][j][k]] >= gr[i][j][k])
						ok(i,l,k,gr[j + 1][l][gr[i][j][k]]);
					if (gl[i][j][k] <= k && gr[j + 1][l][k] >= k)
						ok(i,l,gl[i][j][k],gr[j + 1][l][k]);
				}
			}
	}
	for (int i = 0;i < n;i++)
		for (int j = 1;j <= tot;j++)
			for (int k = i + 1;k <= n;k++)
				for (int l = j;l <= tot;l++)
					if (gr[i + 1][k][l] >= l)
					{
						f[k][gr[i + 1][k][l]] = max(f[k][gr[i + 1][k][l]],f[i][j] + x[gr[i + 1][k][l]] - x[l]);
						ans = max(ans,f[k][gr[i + 1][k][l]]);
					}
	for (int j = 1;j <= tot;j++)
		ans = max(ans,f[n][j]);
	printf("%d\n",ans);
	return 0;
}