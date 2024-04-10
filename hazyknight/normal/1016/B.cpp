#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

int n,m,q;
int ans[1005][1005];

string s,t;

bool ok[1005];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> q >> s >> t;
	for (int i = 0;i + m - 1 < n;i++)
	{
		ok[i + m] = true;
		for (int j = i;j <= i + m - 1;j++)
			if (s[j] != t[j - i])
			{
				ok[i + m] = false;
				break;
			}
	}
	for (int i = 1;i <= n;i++)
		for (int j = i + m - 1;j <= n;j++)
			ans[i][j] = ans[i][j - 1] + ok[j];
	for (int l,r,i = 1;i <= q;i++)
	{
		cin >> l >> r;
		cout << ans[l][r] << endl;
	}
	return 0;
}