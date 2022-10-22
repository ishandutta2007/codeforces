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
	int n;
	cin >> n;
	vector<int> r(n);
	for (int i = 0; i < n; i++)
	{
		cin >> r[i];
	}
	int rs = 0, bs = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		r[i] -= a;
		if (r[i] < 0)
		{
			bs++;
		}
		if (r[i] > 0)
		{
			rs++;
		}
	}
	if (!rs)
	{
		cout << "-1\n";
	}
	else
	{
		for (int i = 1; i <= n+79; i++)
		{
			if (rs * i > bs)
			{
				cout << i << "\n";
				return 0;
			}
		}
	}
	return 0;
}