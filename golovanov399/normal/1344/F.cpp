#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

const int N = 2022;
using Bs = bitset<N>;

const string colors = "WRYB";

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	cin.sync_with_stdio(false);

	int n = nxt(), k = nxt();
	vector<char> c(2 * n);
	for (int i = 0; i < n; ++i) {
		c[2 * i] = 1;
		c[2 * i + 1] = 2;
	}
	vector<Bs> a;
	vector<char> b;
	for (int t = 0; t < k; ++t) {
		string op;
		cin >> op;
		if (op == "mix") {
			int sz = a.size();
			a.push_back({});
			a.push_back({});
			int cnt = nxt();
			for (int i = 0; i < cnt; ++i) {
				int idx = nxt() - 1;
				a[sz].set(2 * idx, c[2 * idx] & 1);
				a[sz].set(2 * idx + 1, c[2 * idx] >> 1);
				a[sz + 1].set(2 * idx, c[2 * idx + 1] & 1);
				a[sz + 1].set(2 * idx + 1, c[2 * idx + 1] >> 1);
			}
			char col;
			cin >> col;
			int x = colors.find(col);
			b.push_back(x & 1);
			b.push_back(x >> 1);
		} else if (op == "RY") {
			int cnt = nxt();
			for (int i = 0; i < cnt; ++i) {
				int idx = nxt() - 1;
				swap(c[2 * idx], c[2 * idx + 1]);
			}
		} else if (op == "RB") {
			int cnt = nxt();
			for (int i = 0; i < cnt; ++i) {
				int idx = nxt() - 1;
				c[2 * idx + 1] ^= c[2 * idx];
			}
		} else if (op == "YB") {
			int cnt = nxt();
			for (int i = 0; i < cnt; ++i) {
				int idx = nxt() - 1;
				c[2 * idx] ^= c[2 * idx + 1];
			}
		}
	}

	int row = 0;
	vector<int> cols;
	for (int col = 0; row < (int)a.size() && col < 2 * n; ++col) {
		if (!a[row][col]) {
			for (int i = row; i < (int)a.size(); ++i) {
				if (a[i][col]) {
					swap(a[i], a[row]);
					swap(b[i], b[row]);
					break;
				}
			}
		}
		if (!a[row][col]) {
			continue;
		}
		cols.push_back(col);
		for (int i = row + 1; i < (int)a.size(); ++i) {
			if (a[i][col]) {
				a[i] ^= a[row];
				b[i] ^= b[row];
			}
		}
		++row;
	}
	for (int i = row; i < (int)a.size(); ++i) {
		if (b[i]) {
			cout << "NO\n";
			return 0;
		}
	}
	vector<int> ans(2 * n);
	for (int i = row - 1; i >= 0; --i) {
		ans[cols[i]] = b[i];
		for (int j = 2 * n - 1; j > cols[i]; --j) {
			if (a[i][j]) {
				ans[cols[i]] ^= ans[j];
			}
		}
	}

	cout << "YES\n";
	for (int i = 0; i < n; ++i) {
		char c = colors[ans[2 * i] + 2 * ans[2 * i + 1]];
		if (c == 'W') {
			c = '.';
		}
		cout << c;
	}
	cout << "\n";

	return 0;
}