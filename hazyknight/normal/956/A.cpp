#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <cctype>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

int n,m;
char c[55][55];

int main()
{
	cin >> n >> m;
	getchar();
	for (int i = 1;i <= n;i++,getchar())
		for (int j = 1;j <= m;j++)
			c[i][j] = getchar();
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			if (c[i][j] == '#')
			{
				for (int k = 1;k <= n;k++)
					for (int l = 1;l <= m;l++)
						if (k != i && l != j)
						{
							if (c[k][j] == '#' && c[i][l] == '#' && c[k][l] != '#')
							{
								cout << "No" << endl;
								return 0;
							}
						}
			}
	cout << "Yes" << endl;
	return 0;
}