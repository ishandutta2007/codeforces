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
	int n, m, cl, ce, v;
	cin >> n >> m >> cl >> ce >> v;
	vector<int> l(cl);
	for (int i = 0; i < cl; i++) cin >> l[i];
	vector<int> e(ce);
	for (int i = 0; i < ce; i++) cin >> e[i];
	sort(l.begin(), l.end());
	sort(e.begin(), e.end());
	int q;
	cin >> q;
	while (q--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2)
		{
			cout << abs(y1 - y2) << "\n";
			continue;
		}
		int best = 1e9;
		auto itl = lower_bound(l.begin(), l.end(), y1);
		if (itl != l.end()) best = min(best, abs(*itl - y1) + abs(x1 - x2) + abs(*itl - y2));
		if (itl != l.begin())
		{
			itl--;
			best = min(best, abs(*itl - y1) + abs(x1 - x2) + abs(*itl - y2));
		}
		auto ite = lower_bound(e.begin(), e.end(), y1);
		if (ite != e.end()) best = min(best, abs(*ite - y1) + divup(abs(x1 - x2), v) + abs(*ite - y2));
		if (ite != e.begin())
		{
			ite--;
			best = min(best, abs(*ite - y1) + divup(abs(x1 - x2), v) + abs(*ite - y2));
		}
		cout << best << "\n";
	}
	return 0;
}