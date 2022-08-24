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

const int mod = 998244353;
using Mint = Modular<mod>;

int main() {
	int n = nxt(), k = nxt(), m = nxt();
	vector<vector<pair<int, int>>> qrs(n);
	for (int i = 0; i < m; ++i) {
		int l = nxt() - 1, r = nxt() - 1, x = nxt();
		qrs[r].push_back({l, x});
	}

	Mint ans = 1;
	for (int bit = 0; bit < k; ++bit) {
		vector<int> is_one(n + 1);
		for (int i = 0; i < n; ++i) {
			for (auto [l, x] : qrs[i]) {
				if (x & (1 << bit)) {
					is_one[l] += 1;
					is_one[i + 1] -= 1;
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			is_one[i] += is_one[i - 1];
		}
		vector<Mint> pref(n + 1);
		int maximal = -1;
		for (int i = 0; i < n; ++i) {
			Mint cur = 0;
			if (!is_one[i]) {
				cur = pref[i] - pref[max(0, maximal)];
				if (maximal == -1) {
					cur += 1;
				}
			}
			pref[i + 1] = pref[i] + cur;
			for (auto [l, x] : qrs[i]) {
				if (!(x & (1 << bit))) {
					maximal = max(maximal, l);
				}
			}
		}
		ans *= pref[n] - pref[max(maximal, 0)] + Mint(maximal == -1 ? 1 : 0);
	}
	cout << ans << "\n";

	return 0;
}