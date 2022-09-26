#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>

using namespace std;

const int MAXN = 2005;

int n,m,cntx,cnty,N;

bool markx[MAXN];
bool marky[MAXN];
bool mark[MAXN][MAXN];

double f[MAXN][MAXN];

double dfs(int i,int j)
{
	if (!i && !j)
		return 0;
	if (mark[i][j])
		return f[i][j];
	mark[i][j] = true;
	f[i][j] = 1;
	if (i && j)
		f[i][j] += (double)(i * j) / N * dfs(i - 1,j - 1);
	if (i)
		f[i][j] += (double)(i * (n - j)) / N * dfs(i - 1,j);
	if (j)
		f[i][j] += (double)((n - i) * j) / N * dfs(i,j - 1);
	f[i][j] *= (double)N / (N - (n - i) * (n - j));
	return f[i][j];
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	N = n * n;
	for (int x,y,i = 1;i <= m;i++)
		cin >> x >> y,markx[x] = marky[y] = true;
	for (int i = 1;i <= n;i++)
	{
		if (!markx[i])
			cntx++;
		if (!marky[i])
			cnty++;
	}
	cout << fixed << setprecision(6) << dfs(cntx,cnty) << endl;
	return 0;
}