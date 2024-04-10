#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>

using namespace std;

const int MAXN = 5005;
const int INF = (1 << 30) - 1;

int n;
int c[MAXN];
int l[MAXN];
int r[MAXN];
int f[MAXN][MAXN];

int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> c[i];
	l[1] = 1;
	for (int i = 2;i <= n;i++)
		if (c[i] == c[i - 1])
			l[i] = l[i - 1];
		else
			l[i] = i;
	r[n] = n;
	for (int i = n - 1;i >= 1;i--)
		if (c[i] == c[i + 1])
			r[i] = r[i + 1];
		else
			r[i] = i;
	for (int i = 1;i <= n;i++)
		for (int j = i;j <= n;j++)
			f[i][j] = INF;
	for (int i = 1;i <= n;i++)
		f[l[i]][r[i]] = 0;
	for (int len = 1;len < n;len++)
		for (int i = 1,j = len;j <= n;i++,j++)
		{
			if (i > 1 && j < n && c[i - 1] == c[j + 1])
				f[l[i - 1]][r[j + 1]] = min(f[l[i - 1]][r[j + 1]],f[i][j] + 1);
			if (i > 1)
				f[l[i - 1]][j] = min(f[l[i - 1]][j],f[i][j] + 1);
			if (j < n)
				f[i][r[j + 1]] = min(f[i][r[j + 1]],f[i][j] + 1);
		}
	cout << f[1][n] << endl;
	return 0;
}