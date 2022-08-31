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
	scanf("%d", &x);
	return x;
}

void solve() {
	int n = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	for (auto& x : a) {
		x -= 1;
	}

	string ans(n, '0');
	vector<int> cnt(n);
	for (int x : a) {
		cnt[x] += 1;
	}
	int l = 0, r = n - 1;
	for (int i = n; i > 0; --i) {
		if (!cnt[n - i]) {
			break;
		}
		ans[i - 1] = '1';
		if (cnt[n - i] > 1) {
			break;
		}
		if (a[l] == n - i) {
			++l;
		} else if (a[r] == n - i) {
			--r;
		} else {
			break;
		}
	}
	if (*min_element(all(cnt)) == 1) {
		ans[0] = '1';
	}
	cout << ans << "\n";
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}