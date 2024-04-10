#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
typedef long long ll;
typedef long double ld;
using namespace std;

ll ans = 0;
void calc(map<int, int> m)
{
	ll s1 = 0;
	ll c1 = 0;
	for (pair<int, int> i : m)
	{
		ans += ((i.first * 1ll * c1) - s1) * ((ll)i.second);
		c1 += i.second;
		s1 += i.second * 1ll * i.first;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	map<int, map<int, int> > x, y;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		int c;
		cin >> c;
		x[c][i]++;
		y[c][j]++;
	}
	for (auto i : x)
	{
		calc(i.second);
	}
	for (auto i : y)
	{
		calc(i.second);
	}
	cout << ans << "\n";
	return 0;
}