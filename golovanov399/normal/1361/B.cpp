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

template <typename T>
T pw(T a, long long b) {
	T res = 1;
	while (b) {
		if (b & 1ll) {
			res = res * a;
		}
		b >>= 1;
		a = a * a;
	}
	return res;
}

const int mod = 1000000007;
using Mint = Modular<mod>;

const long long inf = 3e12;

void solve() {
	int n = nxt(), p = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	if (p == 1) {
		cout << n % 2 << "\n";
		return;
	}
	sort(all(a));
	reverse(all(a));

	Mint pm(p);
	Mint ans = 0;

	long long cur = 0;
	int last = a[0];
	for (int x : a) {
		if (cur) {
			while (abs(cur) < inf && last > x) {
				cur *= p;
				last -= 1;
			}
			if (last > x) {
				last = x;
				cur = (cur > 0) ? inf : -inf;
			}
		}
		last = x;
		if (cur > 0) {
			ans -= pw(pm, x);
			cur -= 1;
		} else {
			ans += pw(pm, x);
			cur += 1;
		}
	}

	if (cur < 0) {
		ans = Mint(0) - ans;
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