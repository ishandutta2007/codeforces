#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 1010;
const int INF = 100000;

int a[MAXN][MAXN];
long long d2[MAXN][MAXN], d5[MAXN][MAXN];

int del(int x, int p)
{
	if (x == 0) return INF;
	int res = 0;
	while (x % p == 0)
	{
		x/=p;
		res++;
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	bool f0;
	int x0, y0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			cin >> a[i][j];
			if (a[i][j] == 0)
			{
				x0 = i;
				y0 = j;
				f0 = true;
			}
		}
	if (a[1][1] == 0)
	{
		cout << "1\n";
		for (int i = 0; i < n-1; ++i)
			cout << "DR";
		return 0;
	}
	for (int i = 2; i <= n; ++i)
		d2[0][i] = d2[i][0] = d5[0][i] = d5[i][0] = INF;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			d2[i][j] = (long long)del(a[i][j], 2) + min(d2[i-1][j], d2[i][j-1]);
			d5[i][j] = (long long)del(a[i][j], 5) + min(d5[i-1][j], d5[i][j-1]);
		}
	if (f0 && min(d2[n][n], d5[n][n]) > 1)
		{
			x0--; y0--;
			cout << 1 << '\n';
			for (int i = 0; i < x0; ++i)
				cout << 'D';
			for (int i = 0; i < y0; ++i)
				cout << 'R';
			for (int i = 0; i < n - x0 - 1; ++i)
				cout << 'D';
			for (int i = 0; i < n - y0 - 1; ++i)
				cout << 'R';
			return 0;
		}
	if (d2[n][n] < d5[n][n])
	{
		cout << d2[n][n] << '\n';
		int x = n;
		int y = n;
		string ans = "";
		while (x != 1 || y != 1)
		{
			if (d2[x-1][y] < d2[x][y-1])
			{
				ans += 'D';
				x--;
			}
			else
			{
				ans += 'R';
				y--;
			}
		}
		for (int i = 0; i < ans.length(); ++i)
			cout << ans[ans.length() - i - 1];
		cout << '\n';
	}
	else
	{
		cout << d5[n][n] << '\n';
		int x = n;
		int y = n;
		string ans = "";
		while (x != 1 || y != 1)
		{
			if (d5[x-1][y] < d5[x][y-1])
			{
				ans += 'D';
				x--;
			}
			else
			{
				ans += 'R';
				y--;
			}
		}
		for (int i = 0; i < ans.length(); ++i)
			cout << ans[ans.length() - i - 1];
	}
	return 0;
}