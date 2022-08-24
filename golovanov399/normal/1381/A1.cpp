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

vector<int> get(string s) {
	vector<int> res;
	for (int i = 0; i < (int)s.length() - 1; ++i) {
		if (s[i] != s[i + 1]) {
			res.push_back(i + 1);
		}
	}
	return res;
}

void solve() {
	int n = nxt();
	string s, t;
	cin >> s >> t;

	auto as = get(s);
	auto at = get(t);
	if (s.back() != t.back()) {
		as.push_back(n);
	}
	reverse(all(at));
	as.insert(as.end(), all(at));
	cout << as.size() << "\n";
	for (int x : as) {
		cout << x << " ";
	}
	cout << "\n";
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