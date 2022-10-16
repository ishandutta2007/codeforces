#include <bits/stdc++.h>

using namespace std;
/*input
2
3 2
3 2
2 1
4 2
1 4
2 3
*/
/*input
1
17 27
1 8
2 9
3 10
4 11
5 12
6 13
7 14
8 9
8 14
8 15
9 10
9 15
10 11
10 15
10 17
11 12
11 17
12 13
12 16
12 17
13 14
13 16
14 16
14 15
15 16
15 17
16 17
*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<long long> gra[n];

		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			a--, b--;
			gra[a].push_back(b);
			gra[b].push_back(a);
		}

		bool vis = true;
		{
			queue<int> eil;
			eil.push(0);
			vector<bool> apl(n, false);

			while (eil.size()) {
				int d = eil.front();
				eil.pop();

				for (auto &&j : gra[d]) {
					if (!apl[j]) {
						apl[j] = true;
						eil.push(j);
					}
				}
			}

			for (auto &&i : apl) {
				vis &= i;
			}
		}

		if (!vis) {
			cout << "NO\n";
			continue;
		}

		set<int> mok;
		set<int> nemok;

		{
			queue<int> eil;
			mok.insert(0);

			for (auto &&i : gra[0]) {
				if (!nemok.count(i)) {
					nemok.insert(i);

					for (auto &&j : gra[i]) {
						eil.push(j);
					}
				}
			}

			while (eil.size()) {
				int d = eil.front();
				eil.pop();

				if (nemok.count(d) or mok.count(d)) {
					continue;
				}
				
				mok.insert(d);

				for (auto &&i : gra[d]) {
					if (!nemok.count(i)) {
						nemok.insert(i);

						for (auto &&j : gra[i]) {
							eil.push(j);
						}
					}
				}
			}
		}

		cout << "YES\n";
		cout << mok.size() << "\n";

		for (auto &&i : mok) {
			cout << i + 1 << " ";
		}

		cout << "\n";
	}
}