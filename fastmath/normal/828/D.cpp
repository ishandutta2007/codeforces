#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>


using namespace std;
#define int long long
int mod = 1e9 + 7;
int big_mod = 1e18 + 7;


vector <pair <int, int> > g;


signed main() {
	cout.precision(20);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int ost1 = n - m - 1;
	int ost2 = m;

	int u = 2;
	int mx1 = 1;
	int mx2 = 1;
	while (ost1) {
		int take = (ost1 - 1) / ost2 + 1;
		g.push_back({ 1, u });
		for (int i = 1; i <= take - 1; ++i) {
			g.push_back({ u + i - 1, u + i });
		}

		g.push_back({ u + take - 1, u + take });
		--ost2;
		u += take + 1;

		if (take + 1 >= mx1) {
			mx2 = mx1;
			mx1 = take + 1;
		}
		else if (take + 1 > mx2) {
			mx2 = take + 1;
		}

		ost1 -= take;
	}

	for (int i = 0; i < ost2; ++i) {
		g.push_back({ 1, u });
		++u;
	}

	cout << mx1 + mx2 << "\n";
	for (int i = 0; i < n - 1; ++i) {
		cout << g[i].first << " " << g[i].second << "\n";
	}

	return 0;
}