#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	int ans = 0;
	for (int _ = 0; _ < 10; ++_) {
		vector<int> fst, snd;
		for (int i = 0; i < n; ++i) {
			if (i & (1 << _)) {
				fst.push_back(i);
			} else {
				snd.push_back(i);
			}
		}
		if (fst.empty() || snd.empty()) {
			continue;
		}
		cout << fst.size() << " " << snd.size();
		for (int x : fst) {
			cout << " " << x + 1;
		}
		for (int x : snd) {
			cout << " " << x + 1;
		}
		cout << endl;
		ans = max(ans, nxt());
	}
	cout << "-1 " << ans << endl;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}