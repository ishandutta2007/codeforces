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
3
2
1 2
1 2
2
2 1
1 2
4
2 3 1 2
2 3 2 3
*/

struct pos {
	long long x, y;
	int p;
	bool operator<(const pos &t)const {
		if (x == t.x) {
			return y < t.y;
		}

		return x < t.x;
	}
};

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int TESTS;
	cin >> TESTS;

	for (int TESTT = 1; TESTT <= TESTS; ++TESTT) {
		int n;
		cin >> n;
		pos a[n];

		for (int i = 0; i < n; ++i) {
			cin >> a[i].x;
		}

		for (int i = 0; i < n; ++i) {
			cin >> a[i].y;
			a[i].p = i;
		}

		sort(a, a + n);
		bool ok = true;

		for (int i = 0; i + 1 < n; ++i) {
			if (a[i].y > a[i + 1].y) {
				ok = false;
			}
		}

		if (!ok) {
			cout << "-1\n";
			continue;
		}

		vector<pair<int, int>> moves;
		int where[n];
		int is[n];

		for (int i = 0; i < n; ++i) {
			where[i] = i;
			is[i] = i;
		}

		for (int i = 0; i < n; ++i) {
			int wi = where[a[i].p];

			if (i == wi) {
				continue;
			}

			moves.push_back({i, wi});
			swap(is[wi], is[i]);
			where[is[i]] = i;
			where[is[wi]] = wi;
		}

		cout << moves.size() << "\n";

		for (auto &&[x, y] : moves) {
			cout << x + 1 << " " << y + 1 << "\n";
		}
	}
}