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
	int a = nxt(), b = nxt();
	const int n = a + b;
	set<int> ans;
	for (int alice_total : {n / 2, (n + 1) / 2}) {
		for (int alice_won_first = 0; alice_won_first <= min(a, alice_total); ++alice_won_first) {
			if (a - alice_won_first <= n - alice_total) {
				ans.insert(alice_total - alice_won_first + (a - alice_won_first));
			}
		}
	}
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