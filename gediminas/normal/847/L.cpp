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
3
2:3,2
1:1-1:3
2:1,2
*/
/*input
5
4:2,5,3,4
1:4-1:1-2:5,3
4:4,5,2,1
4:2,1,3,5
1:3-3:4,2,1

*/
/*input
3
1:2-1:3
1:1-1:3
1:1-1:2
*/
vector<int> gra[1000];
set<int> o;
void reach(int x, int p) {
	o.insert(x);

	for (auto &&y : gra[x]) {
		if (y == p) {
			continue;
		}

		reach(y, x);
	}
}

int main () {
	int n;
	cin >> n;

	vector<vector<int>> a[n];
	set<set<int>> v[n];
	bool pan[n] = {};
	vector<pair<int, int>> ans;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		stringstream cc;
		cc << s;
		char t = '-';

		do {
			int k;
			cc >> k >> t;
			vector<int> b(k);

			for (int j = 0; j < k; ++j) {
				cc >> b[j];
				b[j]--;

				if (!(cc >> t)) {
					t = ' ';
				}
			}

			a[i].push_back(b);
			v[i].emplace(b.begin(), b.end());
		}
		while (t == '-');
	}

	bool egz = true;

	while (egz and ans.size() < n - 1) {
		int p = ans.size();

		for (int i = 0; i < n; ++i) {
			if (pan[i]) {
				continue;
			}

			vector<vector<int>> t;
			swap(t, a[i]);

			for (auto &&tt : t) {
				vector<int> o;

				for (auto &&u : tt) {
					if (!pan[u]) {
						o.push_back(u);
					}
				}

				if (o.size() == 1) {
					pan[o[0]] = true;
					ans.push_back({o[0], i});
				}
				else if (o.size()) {
					a[i].push_back(o);
				}
			}
		}

		if (ans.size() == p) {
			egz = false;
		}
	}

	for (auto &&[x, y] : ans) {
		gra[x].push_back(y);
		gra[y].push_back(x);
	}

	for (int i = 0; i < n; ++i) {
		set<set<int>>p;

		for (auto &&y : gra[i]) {
			o.clear();
			reach(y, i);
			p.insert(o);
		}

		if (p != v[i]) {
			egz = false;
			break;
		}
	}

	if (!egz) {
		cout << "-1";
		exit(0);
	}

	cout << ans.size() << "\n";

	for (auto &&[x, y] : ans) {
		cout << x + 1 << " " << y + 1 << "\n";
	}


	return 0;
}