#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>

using namespace std;

int n,m;

char st[1005][1005];
char ed[1005][1005];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	string s;
	for (int i = 1;i <= n;i++)
	{
		cin >> s;
		for (int j = 1;j <= m;j++)
		{
			st[i][j] = s[j - 1];
			ed[i][j] = '.';
		}
	}
	for (int i = 2;i < n;i++)
		for (int j = 2;j < m;j++)
		{
			bool ok = true;
			for (int k = -1;k <= 1;k++)
				for (int l = -1;l <= 1;l++)
					if (k != 0 || l != 0)
						if (st[i + k][j + l] != '#')
							ok = false;
			if (ok)
			{
				for (int k = -1;k <= 1;k++)
					for (int l = -1;l <= 1;l++)
						if (k != 0 || l != 0)
							ed[i + k][j + l] = '#';
			}
		}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			if (st[i][j] != ed[i][j])
			{
				cout << "NO" << endl;
				return 0;
			}
	cout << "YES" << endl;
	return 0;
}