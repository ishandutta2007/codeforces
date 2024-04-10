#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <iomanip>
#include <vector>

using namespace std;

const int INF = 5e8;

int n;
int a[5005];
int f[5005][5005][5];
int c1[5005];
int c2[5005];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	a[n + 1] = -INF;
	a[n + 2] = -2 * INF;
	a[n + 3] = -3 * INF;
	for (int i = 1;i <= n + 3;i++)
	{
		if (i != 1)
			c1[i] += max(0,a[i - 1] - a[i] + 1);
		if (i != n + 3)
			c1[i] += max(0,a[i + 1] - a[i] + 1);
	//	cout << c1[i] << ' ';
	}
//	cout << endl;
//	system("pause");
	for (int i = 2;i <= n + 2;i++)
		c2[i] = min(max(0,a[i] - a[i - 1] + 1),max(0,a[i] - a[i + 1] + 1));
	for (int i = 3;i <= n + 3;i++)
		for (int j = 0;j <= (i + 1) / 2;j++)
			for (int k = 0;k < 5;k++)
				f[i][j][k] = INF;
	f[3][0][0] = 0;
	f[3][1][1] = c1[3];
	f[3][1][2] = c1[2];
	f[3][1][3] = c1[1];
	f[3][2][4] = c1[1] + c1[3] - c2[2];
	for (int i = 3;i <= n + 2;i++)
		for (int j = 0;j <= (i + 1) / 2;j++)
		{
			if (f[i][j][0] != INF)
			{
			//	cout << "f[" << i << "][" << j << "][000]=" << f[i][j][0] << endl;
				f[i + 1][j][0] = min(f[i + 1][j][0],f[i][j][0]);
				f[i + 1][j + 1][1] = min(f[i + 1][j + 1][1],f[i][j][0] + c1[i + 1]);
			}
			if (f[i][j][1] != INF)
			{
			//	cout << "f[" << i << "][" << j << "][001]=" << f[i][j][1] << endl;
				f[i + 1][j][2] = min(f[i + 1][j][2],f[i][j][1]);
			}
			if (f[i][j][2] != INF)
			{
			//	cout << "f[" << i << "][" << j << "][010]=" << f[i][j][2] << endl;
				f[i + 1][j][3] = min(f[i + 1][j][3],f[i][j][2]);
				f[i + 1][j + 1][4] = min(f[i + 1][j + 1][4],f[i][j][2] + c1[i + 1] - c2[i]);
			}
			if (f[i][j][3] != INF)
			{
			//	cout << "f[" << i << "][" << j << "][100]=" << f[i][j][3] << endl;
				f[i + 1][j][0] = min(f[i + 1][j][0],f[i][j][3]);
				f[i + 1][j + 1][1] = min(f[i + 1][j + 1][1],f[i][j][3] + c1[i + 1]);
			}
			if (f[i][j][4] != INF)
			{
			//	cout << "f[" << i << "][" << j << "][101]=" << f[i][j][4] << endl;
				f[i + 1][j][2] = min(f[i + 1][j][2],f[i][j][4]);
			}
		}
	for (int i = 1;i <= (n + 1) / 2;i++)
		cout << f[n + 3][i][0] << ' ';
	cout << endl;
	return 0;
}