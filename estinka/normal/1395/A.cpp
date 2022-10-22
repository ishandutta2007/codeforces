#ifdef __GNUG__
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <chrono>
#endif
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
		ll r, g, b, w;
		cin >> r >> g >> b >> w;
		multiset<ll> m2;
		m2.insert(r % 2);
		m2.insert(g % 2);
		m2.insert(b % 2);
		m2.insert(w % 2);
		if (m2.count(1) <= 1)
		{
			cout << "Yes" << "\n";
			continue;
		}
		m2.clear();
		if (r && g && b)
		{
			r--; g--; b--;
			w += 3;
			m2.insert(r % 2);
			m2.insert(g % 2);
			m2.insert(b % 2);
			m2.insert(w % 2);
			if (m2.count(1) <= 1)
			{
				cout << "Yes" << "\n";
				continue;
			}
		}
		cout << "No\n";
	}
	return 0;
}