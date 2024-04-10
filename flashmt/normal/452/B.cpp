#include <bits/stdc++.h>
using namespace std;

double dist(int x, int y)
{
	return sqrt(x * x + y * y);
}

int main()
{
	ios::sync_with_stdio(0);
	int m, n;
	
	cin >> m >> n;
	if (!m)
	{
		cout << 0 << ' ' << 1 << endl;
		cout << 0 << ' ' << n << endl;
		cout << 0 << ' ' << 0 << endl;
		cout << 0 << ' ' << n - 1 << endl;
		return 0;
	}
	
	if (!n)
	{
		cout << 1 << ' ' << 0 << endl;
		cout << m << ' ' << 0 << endl;
		cout << 0 << ' ' << 0 << endl;
		cout << m - 1 << ' ' << 0 << endl;
		return 0;
	}

	if (m <= n)
	{
		double ans = dist(m, n) * 2 + n;
		int ansX = m;
		for (int x = 1; x < m; x++)
		{
			double length = dist(m, n) + dist(x, n) + dist(m - x, n);
			if (length > ans) ans = length, ansX = x;
		}
		
		double length = dist(m, n) + dist(m - 1, n) * 2;
		if (length > ans)
		{
			cout << 1 << ' ' << 0 << endl;
			cout << m << ' ' << n << endl;
			cout << 0 << ' ' << 0 << endl;
			cout << m - 1 << ' ' << n << endl;
		}
		else
		{
			cout << 0 << ' ' << 0 << endl;
			cout << m << ' ' << n << endl;
			cout << ansX << ' ' << 0 << endl;
			cout << 0 << ' ' << n << endl;
		}
		
		return 0;
	}
	
	double ans = dist(m, n) * 2 + m;
	int ansY = n;
	for (int y = 1; y < n; y++)
	{
		double length = dist(m, n) + dist(m, y) + dist(m, n - y);
		if (length > ans) ans = length, ansY = y;
	}
	
	double length = dist(m, n) + dist(m, n - 1) * 2;
	if (length > ans)
	{
		cout << 0 << ' ' << 1 << endl;
		cout << m << ' ' << n << endl;
		cout << 0 << ' ' << 0 << endl;
		cout << m << ' ' << n - 1 << endl;
	}
	else
	{
		cout << 0 << ' ' << 0 << endl;
		cout << m << ' ' << n << endl;
		cout << 0 << ' ' << ansY << endl;
		cout << m << ' ' << 0 << endl;
	}
}