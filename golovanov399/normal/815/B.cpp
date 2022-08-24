#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int f(vector<int> a) {
	vector<int> b;
	int sign = 1;
	while (a.size() > 1) {
		for (int i = 0; i < (int)a.size() - 1; ++i) {
			b.push_back(a[i] + sign * a[i + 1]);
			sign *= -1;
		}
		a.swap(b);
		b.clear();
	}
	return a[0];
}

const int mod = 1000000007;

const int N = 222222;
int inv[N];

vector<long long> get_C(int n) {
	vector<long long> res(n + 1, 1ll);
	for (int i = 1; i < n; ++i) {
		res[i] = res[i - 1] * inv[i] % mod * (n + 1 - i) % mod;
	}
	return res;
}

int main() {
	// for (int n = 1; n <= 40; ++n) {
	// 	if (n % 4 != 3) {
	// 		continue;
	// 	}
	// 	cerr << "n = " << n << ":";
	// 	for (int i = 0; i < n/2; i += 2) {
	// 		vector<int> tmp(n, 0);
	// 		tmp[i] = 1;
	// 		cerr << " " << f(tmp);
	// 	}
	// 	cerr << "\n";
	// }

	inv[1] = 1;
	for (int i = 2; i < N; ++i) {
		inv[i] = mod - 1ll * inv[mod % i] * (mod / i) % mod;
	}

	for (int i = 1; i < 100; ++i) {
		assert(1ll * inv[i] * i % mod == 1);
	}

	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	vector<int> coeff(n, 0);
	if (n == 3) {
		coeff = {1, 2, mod - 1};
	} else if (n % 4 == 0) {
		auto c = get_C(n / 2 - 1);
		for (int i = 0; i < n; ++i) {
			coeff[i] = c[i / 2];
			if (i % 2 == 1) {
				coeff[i] = mod - coeff[i];
			}
		}
	} else if (n % 4 == 1) {
		auto c = get_C(n / 2);
		for (int i = 0; i < n; ++i) {
			if (i % 2 == 1) {
				continue;
			}
			coeff[i] = c[i / 2];
		}
	} else if (n % 4 == 2) {
		auto c = get_C(n / 2 - 1);
		for (int i = 0; i < n; ++i) {
			coeff[i] = c[i / 2];
		}
	} else if (n % 4 == 3) {
		auto c1 = get_C(n / 2 - 1);
		auto c2 = get_C(n / 2 - 2);
		for (int i = 0; i < n; ++i) {
			if (i % 2 == 1) {
				coeff[i] = c1[i / 2] * 2 % mod;
			} else {
				coeff[i] = i / 2 < (int)c2.size() ? c2[i / 2] : 0;
				if (i / 2 >= 2) {
					coeff[i] -= c2[i / 2 - 2];
				}
				if (coeff[i] < 0) {
					coeff[i] += mod;
				}
			}
		}
	}

	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += 1ll * coeff[i] * a[i] % mod;
	}
	cout << ans % mod << "\n";

	return 0;
}