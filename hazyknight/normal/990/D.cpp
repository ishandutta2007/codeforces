#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <cmath>
#include <map>

using namespace std;

int n,a,b;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> a >> b;
	if (a != 1 && b != 1)
	{
		cout << "NO" << endl;
		return 0;
	}
	if (n == 2 && a == 1 && b == 1)
	{
		cout << "NO" << endl;
		return 0;
	}
	if (n == 3 && a == 1 && b == 1)
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	if (a == 1)
	{
		for (int i = 1;i <= n;i++,cout << endl)
			for (int j = 1;j <= n;j++)
			{
				if (i == j)
					cout << 0;
				else if (j == i + 1 && j <= n - b + 1)
					cout << 0;
				else if (i == j + 1 && i <= n - b + 1)
					cout << 0;
				else
					cout << 1;
			}
	}
	else
	{
		for (int i = 1;i <= n;i++,cout << endl)
			for (int j = 1;j <= n;j++)
			{
				if (i == j)
					cout << 0;
				else if (j == i + 1 && j <= n - a + 1)
					cout << 1;
				else if (i == j + 1 && i <= n - a + 1)
					cout << 1;
				else
					cout << 0;
			}
	}
	return 0;
}