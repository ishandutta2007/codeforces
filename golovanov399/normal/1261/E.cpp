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

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(0);

	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	vector<string> ans(n + 1, string(n, '0'));
	vector<int> classes(n + 1, 0);
	vector<vector<int>> by_class(n + 1);
	for (int i = 0; i < n + 1; ++i) {
		by_class[0].push_back(i);
	}

	vector<array<int, 3>> ar(n + 1);
	for (int i = 0; i < n; ++i) {
		int x = 0;
		for (int j = 0; j <= n; ++j) {
			if ((int)by_class[j].size() > 1) {
				int q = by_class[j][0];
				int w = by_class[j][1];
				if (w + 1 - a[i] > q) {
					x = w + 1 - a[i];
				} else {
					x = q + 1;
				}
				break;
			}
		}
		for (int j = 0; j < a[i]; ++j) {
			ans[(x + j) % (n + 1)][i] = '1';
		}
		for (int j = 0; j < n + 1; ++j) {
			ar[j][0] = classes[j];
			ar[j][2] = j;
			if (j < a[i]) {
				ar[(x + j) % (n + 1)][1] = 1;
			} else {
				ar[(x + j) % (n + 1)][1] = 0;
			}
		}
		sort(all(ar));
		for (int j = 0; j < n + 1; ++j) {
			by_class[j].clear();
		}
		int cur = 0;
		for (int j = 0; j < n + 1; ++j) {
			if (j > 0 && (ar[j][0] != ar[j - 1][0] || ar[j][1] != ar[j - 1][1])) {
				++cur;
			}
			classes[ar[j][2]] = cur;
			by_class[cur].push_back(ar[j][2]);
		}
	}
	vector<string> filtered;
	for (auto s : ans) {
		if (*max_element(all(s)) == '1') {
			filtered.push_back(s);
		}
	}
	cout << filtered.size() << "\n";
	for (auto s : filtered) {
		cout << s << "\n";
	}

	return 0;
}