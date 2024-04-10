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
		vector<int> p(n);
		for (int i = 0; i < n; i++)
		{
			cin >> p[i];
		}
		reverse(p.begin(), p.end());
		for (int i = 0; i < n; i++)
		{
			cout << p[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}