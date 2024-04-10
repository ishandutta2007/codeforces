#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

template <typename T>
struct TypeModular {
	using Type = typename decay<decltype(T::value)>::type;
	Type val;

	static constexpr Type mod() {
		return T::value;
	}

	TypeModular(long long _val = 0) {
		if (_val < 0 || _val >= mod()) {
			val = _val % mod();
			if (val < 0) {
				val += mod();
			}
		} else {
			val = _val;
		}
	}

	friend TypeModular operator -(const TypeModular& a) {
		return {-a.val};
	}

	friend TypeModular operator +(const TypeModular& a, const TypeModular& b) {
		Type res = a.val + b.val;
		if (res >= mod()) {
			res -= mod();
		}
		return {res};
	}

	friend TypeModular operator -(const TypeModular& a, const TypeModular& b) {
		Type res = a.val - b.val;
		if (res < 0) {
			res += mod();
		}
		return {res};
	}

	friend TypeModular operator *(const TypeModular& a, const TypeModular& b) {
		return {1ll * a.val * b.val};
	}

	friend TypeModular operator /(const TypeModular& a, const TypeModular& b) {
		return a * b.inv();
	}

	TypeModular& operator +=(const TypeModular& b) {
		val += b.val;
		if (val >= mod()) {
			val -= mod();
		}
		return *this;
	}

	TypeModular& operator -=(const TypeModular& b) {
		val -= b.val;
		if (val < 0) {
			val += mod();
		}
		return *this;
	}

	TypeModular& operator *=(const TypeModular& b) {
		val = 1ll * val * b.val % mod();
		return *this;
	}

	TypeModular& operator /=(const TypeModular& b) {
		*this *= b.inv();
		return *this;
	}

	TypeModular& operator ++() {
		val += 1;
		if (val == mod()) {
			val = 0;
		}
		return *this;
	}

	TypeModular operator ++(int) {
		TypeModular tmp(*this);
		operator ++();
		return tmp;
	}

	friend bool operator ==(const TypeModular& a, const TypeModular& b) {
		return a.val == b.val;
	}

	friend bool operator !=(const TypeModular& a, const TypeModular& b) {
		return a.val != b.val;
	}

	TypeModular pow(long long b) const {
		TypeModular res{1}, a{*this};
		while (b) {
			if (b & 1ll) {
				res *= a;
			}
			b >>= 1;
			a *= a;
		}
		return res;
	}

	TypeModular inv() const {
		assert(val);
		return _inv(val, mod());
	}

	int _inv(int a, int b) const {
		return a == 1 ? a : b - 1ll * _inv(b % a, a) * b / a % b;
	}

	explicit operator Type() const {
		return val;
	}

	explicit operator bool() const {
		return val;
	}
};

template <typename T = int>
struct integral_variable {
	static T value;
};

template <typename T> T integral_variable<T>::value;

void set_prime(int p) {
	integral_variable<int>::value = p;
}

template <typename T>
ostream& operator <<(ostream& ostr, const TypeModular<T>& x) {
	return ostr << x.val;
}

template <int mod>
using Modular = TypeModular<integral_constant<int, mod>>;

constexpr int mod = 998'244'353;
using Mint = Modular<mod>;

const int N = 1'111'111;
Mint cnt_upward_trees[N];

Mint rising2(Mint v) {
	return v * (v + 1) / 2;
}

Mint rising3(Mint v) {
	return v * (v + 1) * (v + 2) / 6;
}

void solve() {
	int n = nxt();

	cnt_upward_trees[0] = 1;
	for (int i = 1; i <= n; ++i) {
		Mint v = cnt_upward_trees[i - 1];
		cnt_upward_trees[i] = 1 + v + v * (v + 1) / 2;
	}

	Mint ans = 0;

	// only one side
	ans += (cnt_upward_trees[n - 1] - (n == 1 ? 0 : cnt_upward_trees[n - 2])) * 2 - 1;

	// both sides
	for (int i = 1; i < n; ++i) {
		ans += ((cnt_upward_trees[i] - cnt_upward_trees[i - 1]) - (cnt_upward_trees[i - 1] - (i == 1 ? 0 : cnt_upward_trees[i - 2]))) * (cnt_upward_trees[n - i - 1] - (i == n - 1 ? 0 : cnt_upward_trees[n - i - 2]) - 1);
	}

	// one shitty end with deg = 2
	ans += (rising2(cnt_upward_trees[n - 1]) - (n == 1 ? 0 : rising2(cnt_upward_trees[n - 2]))) * 2;
	// one shitty end with deg = 3
	ans += (rising3(cnt_upward_trees[n - 1]) - (n == 1 ? 0 : rising3(cnt_upward_trees[n - 2]))) * 2;

	cout << ans << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}