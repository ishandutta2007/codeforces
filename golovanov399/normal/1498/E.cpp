#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

bool ask(int i, int j) {
	cout << "? " << i + 1 << " " << j + 1 << endl;
	string s;
	cin >> s;
	return s == "Yes";
}

void solve() {
	int n = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	vector<int> p(n);
	iota(all(p), 0);
	sort(all(p), [&](int i, int j) {
		return a[i] < a[j];
	});
	for (int len = n - 1; len > 0; --len) {
		for (int i = 0; i < n - len; ++i) {
			if (ask(p[i + len], p[i])) {
				cout << "! " << p[i + len] + 1 << " " << p[i] + 1 << endl;
				return;
			}
		}
	}
	cout << "! 0 0" << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}