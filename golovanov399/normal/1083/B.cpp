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

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	cin.sync_with_stdio(0);

	int n, k;
	cin >> n >> k;
	string s, t;
	cin >> s >> t;
	long long ans = 0;
	long long cur = 0;
	int i = 0;
	while (i < n && s[i] == t[i]) {
		ans += 1;
		++i;
	}
	if (k == 1) {
		cout << n << "\n";
		return 0;
	}
	bool first_time = true;
	while (i < n) {
		long long can = cur * 2;
		if (!first_time) {
			can += 2;
		} else {
			first_time = false;
		}
		if (s[i] == 'a') {
			++can;
		}
		if (t[i] == 'b') {
			++can;
		}
		cur = min<long long>(can, k);
		ans += cur;
		cur -= 2;
		++i;
	}

	cout << ans << "\n";

	return 0;
}