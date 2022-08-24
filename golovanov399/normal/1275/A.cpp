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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	string s;
	cin >> s;
	int n = s.length();
	vector<int> ans;
	vector<char> used(n);
	for (int i = 0; i < n - 4; ++i) {
		if (s.substr(i, 5) == "twone") {
			ans.push_back(i + 2);
			for (int j = i; j < i + 5; ++j) {
				used[j] = 1;
			}
		}
	}
	for (int i = 0; i < n - 2; ++i) {
		if (used[i]) {
			continue;
		}
		if (s.substr(i, 3) == "two" || s.substr(i, 3) == "one") {
			ans.push_back(i + 1);
			for (int j = i; j < i + 3; ++j) {
				used[j] = 1;
			}
		}
	}
	cout << ans.size() << "\n";
	for (int x : ans) {
		cout << x + 1 << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}