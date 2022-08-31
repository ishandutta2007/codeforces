#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
//	freopen("", "rt", stdin);
//	freopen("", "wt", stdout);
	long long ans[40][40] = {0};
	int n, h;
	cin >> n >> h;
	for (int i = 0; i <= n; ++i)
		ans[0][i] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int n1 = 0; n1 < i; ++n1)
				ans[i][j] += ans[n1][j-1] * ans[i - n1 - 1][j-1];
//			cout << ans[i][j] << ' ';
		}
//		cout << '\n';
	}
	cout << ans[n][n] - ans[n][h-1];
	return 0;
}