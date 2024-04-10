#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <set>

using namespace std;

int n;
int a[705];

bool ok[705][705];
bool f[705][705][2];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int i = 1;i <= n;i++)
		for (int j = i + 1;j <= n;j++)
			if (__gcd(a[i],a[j]) != 1)
				ok[i][j] = true;
	for (int i = 1;i <= n;i++)
	{
		if (i > 1 && ok[i - 1][i])
			f[i][i][0] = true;
		if (i < n && ok[i][i + 1])
			f[i][i][1] = true;
	}
	for (int i = 1;i <= n + 1;i++)
		for (int j = 0;j < i;j++)
			f[i][j][0] = f[i][j][1] = true;
	for (int len = 2;len <= n;len++)
		for (int i = 1,j = len;j <= n;i++,j++)
			for (int k = i;k <= j;k++)
				if (f[i][k - 1][1] && f[k + 1][j][0])
				{
					if (i > 1 && ok[i - 1][k])
						f[i][j][0] = true;
					if (j < n && ok[k][j + 1])
						f[i][j][1] = true;
				}
	for (int j = 1;j <= n;j++)
		if (f[1][j - 1][1] && f[j + 1][n][0])
		{
			cout << "Yes" << endl;
			return 0;
		}
	cout << "No" << endl;
	return 0;
}