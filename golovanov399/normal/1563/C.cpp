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

void solve() {
	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt() - 1;
	}
	for (int i = 0; i < n; ++i) {
		if (a[i] % 2 != i % 2) {
			cout << "-1\n";
			return;
		}
	}

	vector<int> ans;
	auto turn = [&](int l) {
		if (l == 1) {
			return;
		}
		assert(l % 2);
		ans.push_back(l);
		reverse(a.begin(), a.begin() + l);
	};

	while (n > 1) {
		turn(find(all(a), n - 1) - a.begin() + 1);
		turn(find(all(a), n - 2) - a.begin());
		turn(find(all(a), n - 2) - a.begin() + 2);
		turn(3);
		turn(n);
		n -= 2;
	}
	assert(is_sorted(all(a)));
	cout << ans.size() << "\n";
	for (int x : ans) {
		cout << x << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}