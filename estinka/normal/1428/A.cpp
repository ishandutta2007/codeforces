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
#include <chrono>
typedef long long ll;
typedef long double ld;
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
		ll x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2 || y1 == y2)
		{
			cout << abs(x1 - x2) + abs(y1 - y2) << "\n";
		}
		else
		{
			cout << abs(x1 - x2) + abs(y1 - y2) + 2ll << "\n";
		}
	}
	return 0;
}