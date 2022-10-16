#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

/*input
9
5 1 2 1
5 2 2 2
5 2 2 3
5 2 2 4
5 3 2 3
4 2 1 1
4 3 1 1
4 1 2 3
7 1 4 1
*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int n, d12, d23, d13;
		cin >> n >> d12 >> d23 >> d13;

		if (d13 >= n or d23 >= n or d12 >= n) {
			cout << "NO\n";
			continue;
		}

		vector<pair<int, int>> edg;
		int timer = 4;

		if (d12 + d23 == d13) {
			int d = 1;

			for (int i = 1; i < d12; ++i) {
				edg.push_back({d, timer});
				d = timer++;
			}

			edg.push_back({d, 2});
			d = 2;

			for (int i = 1; i < d23; ++i) {
				edg.push_back({d, timer});
				d = timer++;
			}

			edg.push_back({d, 3});
		}
		else if (d12 + d13 == d23) {
			int d = 2;

			for (int i = 1; i < d12; ++i) {
				edg.push_back({d, timer});
				d = timer++;
			}

			edg.push_back({d, 1});
			d = 1;

			for (int i = 1; i < d13; ++i) {
				edg.push_back({d, timer});
				d = timer++;
			}

			edg.push_back({d, 3});
		}
		else if (d13 + d23 == d12) {
			int d = 1;

			for (int i = 1; i < d13; ++i) {
				edg.push_back({d, timer});
				d = timer++;
			}

			edg.push_back({d, 3});
			d = 3;

			for (int i = 1; i < d23; ++i) {
				edg.push_back({d, timer});
				d = timer++;
			}

			edg.push_back({d, 2});
		}
		else {
			int xx = -1, yy = -1, zz = -1;

			for (int x = 0; x <= n; ++x) {
				int y = d12 - x;
				int z = d13 - x;

				if (y + z == d23 and x > 0 and y > 0 and z > 0 and x + y + z <= n - 1) {
					xx = x;
					yy = y;
					zz = z;
					break;
				}
			}

			if (xx == -1) {
				cout << "NO\n";
				continue;
			}

			int d = 1;

			for (int i = 0; i < xx; ++i) {
				edg.push_back({d, timer});
				d = timer++;
			}

			int bd = d;
			d = 2;

			for (int i = 1; i < yy; ++i) {
				edg.push_back({d, timer});
				d = timer++;
			}

			edg.push_back({d, bd});
			d = 3;

			for (int i = 1; i < zz; ++i) {
				edg.push_back({d, timer});
				d = timer++;
			}

			edg.push_back({d, bd});
		}

		cout << "YES\n";

		while (timer <= n) {
			edg.push_back({timer++, 1});
		}

		for (auto &&[x, y] : edg) {
			cout << x << " " << y << "\n";
		}
	}
}