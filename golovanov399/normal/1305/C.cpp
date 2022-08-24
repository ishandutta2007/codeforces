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

int pw(int a, int b, int m) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % m;
		}
		b >>= 1;
		a = a * a % m;
	}
	return res;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	sort(all(a));
	vector<int> cnt(m);
	long long ans = 1;
	for (int x : a) {
		for (int i = 0; i < m; ++i) {
			ans = 1ll * ans * pw(x % m - i + m, cnt[i], m) % m;
		}
		if (ans == 0) {
			break;
		}
		cnt[x % m] += 1;
	}

	cout << ans << "\n";

	return 0;
}