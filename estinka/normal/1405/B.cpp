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
		int n;
		cin >> n;
		ll inc = 0;
		ll sum = 0;
		for (int i = 0; i < n; i++)
		{
			ll ai;
			cin >> ai;
			if (ai > 0)
			{
				inc += ai;
			}
			if (ai < 0)
			{
				inc += ai;
				if (inc < 0)
				{
					sum -= inc;
					inc = 0;
				}
			}
		}
		cout << sum << "\n";
	}
	return 0;
}