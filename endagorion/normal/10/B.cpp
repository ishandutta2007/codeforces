#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <string>

const int INF = 1000000000;

using namespace std;

int a[100][100] = {0};
int n, k;

int dist(int x, int y)
{
	int res = abs(x - k/2) + abs(y - k/2);
//	cout << "ZOG" << ' ' << x << ' ' << y << ' ' << res << '\n';
	return res;
}

int main()
{
//	freopen("", "rt", stdin);
//	freopen("", "wt", stdout);
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		int l;
		cin >> l;
		int cur, res = INF;
		int busy = 0;
		int xa, ya;
		for (int y = 0; y < k; ++y)
		{
			busy = 0;
			cur = 0;
			for (int j = 0; j < l; ++j)
			{
				busy += a[y][j];
				cur += dist(j, y);
			}
			if (busy == 0 && cur < res)
			{
				res = cur;
				xa = 0;
				ya = y;
			//	cout << "BEST " << xa << ' ' << ya << ' ' << cur << '\n';
			}
			for (int j = l; j < k; ++j)
			{
				busy -= a[y][j-l] - a[y][j];
				cur -= dist(j-l, y) - dist(j, y);
				if (busy == 0 && cur < res)
				{
					res = cur;
					xa = j-l+1;
					ya = y;
			//		cout << "BEST " << xa << ' ' << ya << ' ' << cur << '\n';
				}
			}
		}
		if (res == INF) cout << -1 << '\n';
		else
		{
			cout << ya+1 << ' ' << xa + 1 << ' ' << xa + l << '\n';
			for (int j = xa; j < xa + l; ++j)
				a[ya][j] = 1;
		}
	}		
	return 0;
}