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

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), mod = nxt();
	long long ans = 0;
	long long fact = 1;
	vector<long long> facts(n + 1);
	facts[0] = 1;
	for (int i = 1; i <= n; ++i) {
		facts[i] = facts[i - 1] * i % mod;
	}
	for (int l = 1; l <= n; ++l) {
		fact = fact * l % mod;
		ans += (n - l + 1) * 1ll * (n - l + 1) % mod * fact % mod * facts[n - l] % mod;
	}
	cout << ans % mod << "\n";

	return 0;
}