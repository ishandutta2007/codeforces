#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <random>
#include <list>
#include <array>
#include <fstream>
#include <chrono>
typedef long long ll;
typedef long double ld;
using namespace std;

int divup(int a, int b)
{
	return (a + b - 1) / b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, x1, x2;
	cin >> n >> x1 >> x2;
	vector<pair<int, int> > c(n);
	for (int i = 0; i < n; i++)
	{
		cin >> c[i].first;
		c[i].second = i;
	}
	sort(c.begin(), c.end());
	for (int k = n - 1; k >= 0; k--)
	{
		int k1 = divup(x1, c[k].first), k2 = divup(x2, c[k].first);
		if (k + k1 - 1 < n - 1)
		{
			int val2 = c[k + k1].first;
			int k12 = divup(x2, val2);
			if (k + k1 + k12 - 1 < n)
			{
				cout << "Yes\n";
				cout << k1 << " " << k12 << "\n";
				for (int i = k; i <= k + k1 - 1; i++) cout << c[i].second + 1 << " ";
				cout << "\n";
				for (int i = k + k1; i <= k + k1 + k12 - 1; i++) cout << c[i].second + 1 << " ";
				cout << "\n";
				return 0;
			}
		}
		if (k + k2 - 1 < n - 1)
		{
			int val1 = c[k + k2].first;
			int k21 = divup(x1, val1);
			if (k + k2 + k21 - 1 < n)
			{
				cout << "Yes\n";
				cout << k21 << " " << k2 << "\n";
				for (int i = k + k2; i <= k + k2 + k21 - 1; i++) cout << c[i].second + 1 << " ";
				cout << "\n";
				for (int i = k; i <= k + k2 - 1; i++) cout << c[i].second + 1 << " ";
				cout << "\n";
				return 0;
			}
		}
	}
	cout << "No\n";
	return 0;
}