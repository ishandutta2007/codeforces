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

const int MAXN = 16;
const int MAXM = 10005;

int n,m;
int a[MAXN][MAXM];

bool f[MAXN][1 << MAXN][MAXN];
bool con[MAXN][MAXN];

bool ok(int lim)
{
	memset(f,0,sizeof(f));
	for (int i = 0;i < n;i++)
		for (int j = i + 1;j < n;j++)
		{
			con[i][j] = con[j][i] = true;
			for (int k = 0;k < m;k++)
				if (abs(a[i][k] - a[j][k]) < lim)
				{
					con[i][j] = con[j][i] = false;
					break;
				}
		}
	for (int i = 0;i < n;i++)
		f[i][1 << i][i] = true;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < (1 << n);j++)
			if (j & (1 << i))
				for (int k = 0;k < n;k++)
					if (f[i][j][k])
						for (int l = 0;l < n;l++)
							if ((~j >> l & 1) && con[k][l])
								f[i][j | (1 << l)][l] = true;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			if (f[i][(1 << n) - 1][j])
			{
				bool flag = true;
				for (int k = 0;k < m - 1;k++)
					if (abs(a[j][k] - a[i][k + 1]) < lim)
					{
						flag = false;
						break;
					}
				if (flag)
					return true;
			}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < m;j++)
			cin >> a[i][j];
	int low = 0,high = 1000000000;
	while (low < high)
	{
		int mid = (low + high + 1) >> 1;
		if (ok(mid))
			low = mid;
		else
			high = mid - 1;
	}
	cout << low << endl;
	return 0;
}