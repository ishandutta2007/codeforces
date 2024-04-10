#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

template <int mod>
struct Modular {
	int val;

	Modular(long long _val = 0) {
		if (_val < 0 || _val >= mod) {
			val = _val % mod;
			if (val < 0) {
				val += mod;
			}
		} else {
			val = _val;
		}
	}

	Modular operator +(const Modular& ot) const {
		int res = val + ot.val;
		if (res >= mod) {
			res -= mod;
		}
		return {res};
	}

	Modular operator -(const Modular& ot) const {
		int res = val - ot.val;
		if (res < 0) {
			res += mod;
		}
		return {res};
	}

	Modular operator *(const Modular& ot) const {
		return {1ll * val * ot.val};
	}

	Modular& operator ++() {
		val += 1;
		if (val == mod) {
			val = 0;
		}
		return *this;
	}

	Modular operator ++(int) {
		Modular tmp(*this);
		operator ++();
		return tmp;
	}

	void operator +=(const Modular& ot) {
		val += ot.val;
		if (val >= mod) {
			val -= mod;
		}
	}

	void operator -=(const Modular& ot) {
		val -= ot.val;
		if (val < 0) {
			val += mod;
		}
	}

	void operator *=(const Modular& ot) {
		val = 1ll * val * ot.val % mod;
	}

	operator long long() const {
		return val;
	}
};

template <typename T>
T pw(T a, int b) {
	T res = 1;
	while (b) {
		if (b & 1) {
			res *= a;
		}
		b >>= 1;
		a *= a;
	}
	return res;
}

const int mod = 998244353;
using Mint = Modular<mod>;

int main() {
	int n = nxt();
	Mint ten = 10;
	for (int i = 1; i <= n; ++i) {
		Mint ans = pw(ten, n - i + 1) * Mint(n - i + 1);
		if (i + 1 <= n) {
			ans -= pw(ten, n - i) * Mint(n - i) * Mint(2);
		}
		if (i + 2 <= n) {
			ans += pw(ten, n - i - 1) * Mint(n - i - 1);
		}
		cout << ans << " ";
	}
	cout << "\n";

	return 0;
}