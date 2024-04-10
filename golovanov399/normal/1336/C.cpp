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

	bool operator ==(const Modular& ot) const {
		return val == ot.val;
	}

	bool operator !=(const Modular& ot) const {
		return val != ot.val;
	}
};

template <int mod>
ostream& operator <<(ostream& ostr, const Modular<mod>& x) {
	return ostr << x.val;
}

const int mod = 998244353;
using Mint = Modular<mod>;

const int N = 3033;
Mint dp[N][N];

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	string s, t;
	cin >> s >> t;
	int n = s.length();
	int m = t.length();
	for (int i = 0; i <= n; ++i) {
		dp[i][i] = 1;
	}
	for (int len = 1; len <= n; ++len) {
		char c = s[len - 1];
		for (int i = 0; i + len <= n; ++i) {
			int j = i + len;
			if (i >= m || t[i] == c) {
				dp[i][j] += dp[i + 1][j];
			}
			if (j > m || t[j - 1] == c) {
				dp[i][j] += dp[i][j - 1];
			}
		}
	}
	cout << accumulate(dp[0] + m, dp[0] + n + 1, Mint(0)) << "\n";

	return 0;
}