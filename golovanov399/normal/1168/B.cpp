#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

bool good(const string& s, int l, itn r) {
	for (int i = r - 2; i >= l; i -= 2) {
		int k = (i + r) / 2;
		if (s[i] == s[k] && s[k] == s[r]) {
			return true;
		}
	}
	return false;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	cin.sync_with_stdio(0);

	string s;
	cin >> s;
	int n = s.length();

	long long ans = 0;
	int r = 0;
	for (int i = 0; i < n; ++i) {
		while (r < n && !good(s, i, r)) {
			++r;
		}
		ans += n - r;
	}
	cout << ans << "\n";

	return 0;
}