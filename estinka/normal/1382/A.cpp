// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
typedef long long ll;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<int>a(n), b(m);
		vector<int> f(1079, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			f[a[i]] |= 1;
		}
		for (int i = 0; i < m; i++)
		{
			cin >> b[i];
			f[b[i]] |= 2;
		}
		int ans = -1;
		for (int i = 0; i < 1079; i++)
		{
			if (f[i] == 3)
			{
				ans = i;
				break;
			}
		}
		if (ans > 0)
		{
			cout << "YES\n" << "1 " << ans << "\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}