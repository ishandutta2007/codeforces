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

const int MAXN = 25;
const int MAXM = 1005;

int n;
int cnt[MAXM];
int a[MAXN][MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int v,i = 1;i <= n * n;i++)
	{
		cin >> v;
		cnt[v]++;
	}
	for (int i = 1;i <= n / 2;i++)
		for (int j = 1;j <= n / 2;j++)
		{
			bool ok = 0;
			for (int k = 1;k <= 1000;k++)
				if (cnt[k] >= 4)
				{
					ok = 1;
					a[i][j] = k;
					cnt[k] -= 4;
					break;
				}
			if (!ok)
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			a[i][j] = a[min(i,n - i + 1)][min(j,n - j + 1)];
	if (n & 1)
	{
		for (int i = 1;i <= n / 2;i++)
			if (i != (n + 1) / 2)
			{
				bool ok = 0;
				for (int j = 1;j <= 1000;j++)
					if (cnt[j] >= 2)
					{
						ok = 1;
						cnt[j] -= 2;
						a[(n + 1) / 2][i] = a[(n + 1) / 2][n - i + 1] = j;
						break;
					}
				if (!ok)
				{
					cout << "NO" << endl;
					return 0;
				}
			}
		for (int i = 1;i <= n / 2;i++)
			if (i != (n + 1) / 2)
			{
				bool ok = 0;
				for (int j = 1;j <= 1000;j++)
					if (cnt[j] >= 2)
					{
						ok = 1;
						cnt[j] -= 2;
						a[i][(n + 1) / 2] = a[n - i + 1][(n + 1) / 2] = j;
						break;
					}
				if (!ok)
				{
					cout << "NO" << endl;
					return 0;
				}
			}
		bool ok = 0;
		for (int j = 1;j <= 1000;j++)
			if (cnt[j] >= 1)
			{
				ok = 1;
				cnt[j]--;
				a[(n + 1) / 2][(n + 1) / 2] = j;
				break;
			}
		if (!ok)
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	for (int i = 1;i <= n;i++,cout << endl)
		for (int j = 1;j <= n;j++)
			cout << a[i][j] << ' ';
	return 0;
}