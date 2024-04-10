#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>

using namespace std;

int n,m,minus_;
int MAX[2][105];
int f[20][2];

bool flag;

int main()
{
	cin >> n >> m;
	getchar();
	for (int i = 1;i <= n;i++,getchar())
	{
		for (int j = 0;j <= m + 1;j++)
		{
			bool light = getchar() - '0';
			flag |= light;
			if (light)
			{
				MAX[0][n - i + 1] = max(MAX[0][n - i + 1],m + 1 - j);
				MAX[1][n - i + 1] = max(MAX[1][n - i + 1],j);
			}
		}
		if (!flag)
			minus_++;
		//cout << MAX[0][n - i + 1] << ' ' << MAX[1][n - i + 1] << endl;
	}
	n -= minus_;
	f[0][1] = 99999999;
	for (int i = 1;i < n;i++)
	{
		f[i][0] = min(f[i - 1][0] + (MAX[1][i] << 1),f[i - 1][1] + m + 1);
		f[i][1] = min(f[i - 1][0] + m + 1,f[i - 1][1] + (MAX[0][i] << 1));
		if (i != 1)
			f[i][0]++,f[i][1]++;
		//cout << f[i][0] << ' ' << f[i][1] << endl;
	}
	if (n == 0)
		cout << 0 << endl;
	else
		cout << min(f[n - 1][0] + MAX[1][n],f[n - 1][1] + MAX[0][n]) + ((n == 1) ? 0 : 1) << endl;
	return 0;
}