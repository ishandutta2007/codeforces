#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

int ask(string op, int i, int j) {
	cout << op << " " << i + 1 << " " << j + 1 << endl;
	return nxt();
}

void solve() {
	int n = nxt(), k = nxt();
	vector<int> a(n);
	{
		int ors[3][3];
		int ands[3][3];
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < i; ++j) {
				ors[i][j] = ors[j][i] = ask("or", i, j);
				ands[i][j] = ands[j][i] = ask("and", i, j);
			}
		}
		for (int i = 0; i < 30; ++i) {
			for (int k = 0; k < 3; ++k) {
				int l = (k + 1) % 3;
				if (ands[k][l] & (1 << i)) {
					a[k] |= 1 << i;
					a[l] |= 1 << i;
				}
			}
			for (int k = 0; k < 3; ++k) {
				int l = (k + 1) % 3;
				int m = (l + 1) % 3;
				if (!(ors[l][m] & (1 << i)) && (ors[k][l] & (1 << i))) {
					a[k] |= 1 << i;
				}
			}
		}
	}
	for (int i = 3; i < n; ++i) {
		int x = ask("or", 0, i);
		int y = ask("and", 0, i);
		for (int j = 0; j < 30; ++j) {
			if (a[0] & (1 << j)) {
				if (y & (1 << j)) {
					a[i] |= 1 << j;
				}
			} else {
				if (x & (1 << j)) {
					a[i] |= 1 << j;
				}
			}
		}
	}
	sort(all(a));
	cout << "finish " << a[k - 1] << endl;
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}