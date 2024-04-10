#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

int n;
int ans;
int a[5][105][105];
int b[205][205];

int main()
{
	cin >> n;
	ans = n * n * 4;
	int c[5] = {0,1,2,3,4};
	for (int i = 1;i <= 4;i++)
		for (int j = 1;j <= n;j++)
		{
			string s;
			cin >> s;
			for (int k = 1;k <= n;k++)
				a[i][j][k] = s[k - 1] - '0';
		}
	int t = 0;
	do
	{
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				b[i][j] = a[c[1]][i][j];
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				b[i + n][j] = a[c[2]][i][j];
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				b[i][j + n] = a[c[3]][i][j];
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				b[i + n][j + n] = a[c[4]][i][j];
		int cnt = 0;
		for (int i = 1;i <= n * 2;i++)
			for (int j = 1;j <= n * 2;j++)
				if (b[i][j] != ((i + j) & 1))
					cnt++;
		ans = min(ans,cnt);
		ans = min(ans,n * n * 4 - cnt);
	}while (next_permutation(c + 1,c + 4 + 1));
	cout << ans << endl;
	return 0;
}