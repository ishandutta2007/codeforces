
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
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	// Mozme si dovolit kubicke riesenie:
	// Zvolime si odpoved a pre kazde a[i] vyskusame najst vhidne b[j]
	const int maxi = 1 << 9;
	int mini = maxi;
	for (int o = 0; o < maxi; o++)
	{
		bool pos = true;
		for (int i = 0; i < n; i++)
		{
			bool good = false;
			for (int j = 0; j < m; j++)
			{
				if (((a[i] & b[j]) | o) == o) // nepridame ziadne bity
				{
					good = true;
					break;
				}
			}
			if (!good)
			{
				pos = false;
				break;
			}
		}
		if (pos)
		{
			mini = min(mini, o);
		}
	}
	cout << mini << "\n";
	return 0;
}