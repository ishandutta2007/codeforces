#include <bits/stdc++.h>
using namespace std;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

/*input
5

2 2
1 2
3 4

4 3
1 3 1
3 1 1
1 2 2
1 1 3

2 3
5 3 4
2 5 1

4 2
7 9
8 1
9 6
10 8

2 4
6 5 2 1
7 9 7 2

*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int ttt;
	cin >> ttt;

	while (ttt--) {
		int m, n;
		cin >> m >> n;
		vector<pair<int, pair<int, int>>> a;

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				int x;
				cin >> x;
				a.push_back({x, {i, j}});
			}
		}

		sort(a.rbegin(), a.rend());
		long long t = 0;
		long long tt = 0;
		int dyd[m] = {};
		set<pair<int, int> > k;
		long long ans = 1000000000000;
		bool buv[n] = {};

		for (auto &&[x, yz] : a) {
			auto &&[y, z] = yz;
			if(!buv[z]){
				buv[z] = true;
				tt++;
			}
			ans = x;

			if (k.count({dyd[y], y})) {
				t++;
				k.erase({dyd[y], y});
				dyd[y]++;
				k.insert({dyd[y], y});
			}
			else {
				dyd[y]++;

				if (k.size() < n - 1) {
					t += dyd[y];
					k.insert({dyd[y], y});
				}
				else {
					if (k.size() and k.begin()->first < dyd[y]) {
						t += dyd[y];
						t -= k.begin()->first;
						k.erase(k.begin());
						k.insert({dyd[y], y});
					}
				}
			}

			debug(k, x, y, t);

			if (t >= n and tt == n) {
				break;
			}
		}

		cout << ans << "\n";
	}

}