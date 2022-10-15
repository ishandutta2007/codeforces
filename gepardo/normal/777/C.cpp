#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	vector< vector<int> > a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	vector<int> rRng(n);
	vector<int> badInCols(m, 0);
	int l = 0, r = 0;
	auto incLeft = [&]() {
		l++;
		if (l < n) {
			for (int i = 0; i < m; i++) {
				if (a[l][i] < a[l-1][i]) {
					badInCols[i]--;
				}
			}
		}
	};
	auto incRight = [&]() {
		r++;
		if (r < n) {
			for (int i = 0; i < m; i++) {
				if (a[r][i] < a[r-1][i]) {
					badInCols[i]++;
				}
			}
		}
	};
	auto good = [&]() -> bool {
		for (int i = 0; i < m; i++) {
			if (!badInCols[i]) {
				return true;
			}
		}
		return false;
	};
	for (int i = 0; i < n; i++) {
		while (r < n && good()) {
			incRight();
		}
		rRng[l] = r;
		incLeft();
	}
	int k; cin >> k;
	for (int i = 0; i < k; i++) {
		int l, r; cin >> l >> r; l--, r--;
		cout << ((r < rRng[l]) ? "Yes" : "No") << "\n";
	}
	return 0;
}