#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

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

const int N = 5055;
Mint A[N][N];
Mint Al[N][N];
Mint fact[N], inv[N], invfact[N];

int main() {
	A[0][0] = 1;
	for (int n = 1; n < N - 10; ++n) {
		for (int i = 0; i < n; ++i) {
			A[n][i] += A[n - 1][i] * i;
			A[n][i + 1] -= A[n - 1][i] * i;
			A[n][i] += A[n - 1][i];
			A[n][i + 1] += A[n - 1][i] * (n - 1);
		}
	}
	for (int n = 0; n < N - 10; ++n) {
		for (int i = 0; i < N; ++i) {
			Al[n][i] = A[n][i];
			if (i) {
				Al[n][i] += Al[n][i - 1];
			}
		}
	}
	fact[0] = invfact[0] = 1;
	for (int i = 1; i < N; ++i) {
		inv[i] = (i == 1) ? 1 : Mint(0) - inv[mod % i] * (mod / i);
		fact[i] = fact[i - 1] * i;
		invfact[i] = invfact[i - 1] * inv[i];
	}

	int n = nxt();
	vector<Mint> sum(n);
	for (int k = 1; k < n; ++k) {
		for (int i = 1; i <= n; ++i) {
			Mint cur = Al[i][k - 1] * fact[n] * invfact[i];
			// cerr << "there are " << cur << " permutations where pos_" << k << " >= " << i << "\n";
			sum[k] += cur;
		}
	}
	sum.push_back(fact[n] * n);

	for (int i = 0; i < n; ++i) {
		cout << sum[i + 1] - sum[i] << " ";
	}
	cout << "\n";

	return 0;
}