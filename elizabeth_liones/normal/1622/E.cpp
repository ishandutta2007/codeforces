#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
typedef long long ll;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> x(n);
		for (int i = 0; i < n; i++) cin >> x[i];
		vector<string> v(n);
		for (int i = 0; i < n; i++) cin >> v[i];
		ll ans = -1;
		vector<pair<int, int> > best;
		for (int good = 0; good < (1 << n); good++)
		{
			vector<pair<int, int> > my(m);
			ll val = 0;
			for (int i = 0; i < n; i++)
			{
				if (good & (1 << i)) val -= x[i];
				else val += x[i];
			}
			for (int i = 0; i < m; i++)
			{
				my[i].second = i;
				for (int j = 0; j < n; j++) if (v[j][i] == '1')
				{
					if (good & (1 << j))
					{
						my[i].first++;
					}
					else
					{
						my[i].first--;
					}
				}
			}
			sort(my.begin(), my.end());
			for (int i = 0; i < m; i++) val += my[i].first * 1ll * (i + 1);
			if (val > ans)
			{
				ans = val;
				best = my;
			}
		}
		vector<int> p(m);
		for (int i = 0; i < m; i++) p[best[i].second] = i + 1;
		for (int i = 0; i < m; i++) cout << p[i] << " \n"[i == m - 1];
	}
	return 0;
}