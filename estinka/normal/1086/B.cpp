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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, s;
	cin >> n >> s;
	if (n == 2)
	{
		cout << s << "\n";
		return 0;
	}
	vector<int> d(n);
	for (int i = 0, x, y; i < n - 1; i++)
	{
		cin >> x >> y;
		d[--x]++;
		d[--y]++;
	}
	int leafs = count(d.begin(), d.end(), 1);
	cout << setprecision(10) << fixed << ((ld)s / (ld)leafs) * (ld)(2.) << "\n";
	return 0;
}