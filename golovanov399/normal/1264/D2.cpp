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

const int mod = 998244353;

const int N = 5111111;
long long fact[N], inv[N], invfact[N];

long long C(int n, int k) {
	if (k < 0 || k > n) {
		return 0;
	}
	return fact[n] * invfact[k] % mod * invfact[n - k] % mod;
}

long long sum(int n, int m, int c) {
	return n * C(n + m - 1, c - 1) % mod;
}

long long sum0(int n, int m, int c) {
	return C(n + m, c);
}

long long f(int c1, int o1, int c2, int o2) {
	if (c1 < c2) {
		swap(c1, c2);
		swap(o1, o2);
	}
	return (sum(o1, o2, o2 - c1 + c2) + c1 * sum0(o1, o2, o2 - c1 + c2)) % mod;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(0);
	string s;
	cin >> s;
	int n = s.length();

	fact[0] = invfact[0] = 1;
	for (int i = 1; i < N; ++i) {
		inv[i] = (i == 1) ? 1 : mod - mod / i * inv[mod % i] % mod;
		fact[i] = fact[i - 1] * i % mod;
		invfact[i] = invfact[i - 1] * inv[i] % mod;
	}

	int cnt_l = 0, cnt_r = 0, open_l = 0, open_r = 0;
	for (char c : s) {
		if (c == '?') {
			open_r += 1;
		} else if (c == ')') {
			cnt_r += 1;
		}
	}

	long long ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] == '(') {
			++cnt_l;
		} else if (s[i] == ')') {
			--cnt_r;
		} else {
			++open_l;
			--open_r;
		}
		// cerr << cnt_l << " " << open_l << " " << cnt_r << " " << open_r << ": " << f(cnt_l, open_l, cnt_r, open_r) << "\n";
		ans += f(cnt_l, open_l, cnt_r, open_r);
	}

	cout << ans % mod << "\n";

	return 0;
}