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

void solve() {
	int n = nxt(), k = nxt();
	string s;
	cin >> s;
	int w_count = 0;
	for (char c : s) {
		w_count += c == 'W';
	}
	if (w_count + k >= n) {
		cout << 2 * n - 1 << "\n";
		return;
	}

	vector<int> betw;
	int cur = 0;
	for (char c : s) {
		if (c == 'L') {
			++cur;
		} else {
			if (cur) {
				betw.push_back(cur);
			}
			cur = 0;
		}
	}
	if (cur > 0) {
		betw.push_back(cur);
	}

	if (s[0] == 'L') {
		betw.erase(betw.begin());
	}
	if (s.back() == 'L' && w_count) {
		betw.pop_back();
	}
	sort(all(betw));
	int score = 2 * (w_count + k);
	if (w_count == 0) {
		cout << max(0, score - 1) << "\n";
		return;
	}
	reverse(all(betw));
	while (!betw.empty() && k >= betw.back()) {
		k -= betw.back();
		betw.pop_back();
	}
	cout << score - (int)betw.size() - 1 << "\n";
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}