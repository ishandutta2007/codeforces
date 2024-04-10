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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

const int mod = 1000000007;
using Mint = Modular<mod>;

struct Fenwick {
	int n;
	vector<Mint> a;

	Fenwick(int _n): n(_n), a(_n) {}

	void add(int pos, Mint x) {
		while (pos < n) {
			a[pos] += x;
			pos |= pos + 1;
		}
	}

	Mint get(int pos) {
		Mint res = 0;
		while (pos >= 0) {
			res += a[pos];
			pos = (pos & (pos + 1)) - 1;
		}
		return res;
	}

	Mint get(int l, int r) {
		return get(r) - get(l - 1);
	}
};

const int L = 20;
const int N = 1111111;
int pr[N][L];
Mint sum[N][L];

int main() {
	cin.sync_with_stdio(false);
	string s;
	cin >> s;

	if (*max_element(all(s)) == '0') {
		cout << (int)s.length() << "\n";
		return 0;
	}

	vector<int> a = {0};
	for (char c : s) {
		if (c == '0') {
			a.back() += 1;
		} else {
			a.push_back(0);
		}
	}
	Mint mult = a[0] + 1;
	mult *= a.back() + 1;
	a.pop_back();
	a.erase(a.begin());
	int n = a.size();

	memset(pr, -1, sizeof(pr));
	{
		vector<pair<int, int>> ar;
		for (int i = 0; i < n; ++i) {
			ar.push_back({a[i], i});
		}
		sort(all(ar));
		reverse(all(ar));
		set<int> S;
		for (auto p : ar) {
			int i = p.second;
			auto it = S.lower_bound(i);
			if (it != S.begin()) {
				pr[i][0] = *prev(it);
			}
			S.insert(i);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < L - 1; ++j) {
			if (~pr[i][j]) {
				pr[i][j + 1] = pr[pr[i][j]][j];
			}
		}
	}

	Fenwick f(n);
	vector<Mint> dp(n);
	for (int i = 0; i < n; ++i) {
		int j = i - 1;
		if (j == -1) {
			dp[i] = a[i] + 1;
		} else {
			dp[i] = dp[j] * (a[i] + 1);
			for (int l = L - 1; l >= 0; --l) {
				if (~pr[j][l] && a[i] > a[pr[j][l]]) {
					dp[i] += f.get(pr[j][l], j - 1) * a[i] - sum[j][l];
					j = pr[j][l];
				}
			}
			// while (a[i] > a[j] && ~pr[j][0]) {
			// 	dp[i] += f.get(pr[j][0], j - 1) * (a[i] - a[j]);
			// 	j = pr[j][0];
			// }
			if (a[i] > a[j]) {
				if (~pr[j][0]) {
					dp[i] += f.get(pr[j][0], j - 1) * (a[i] - a[j]);
				} else {
					dp[i] += (f.get(0, j - 1) + 1) * (a[i] - a[j]);
				}
			}
		}
		f.add(i, dp[i]);

		if (~pr[i][0]) {
			sum[i][0] = f.get(pr[i][0], i - 1) * a[i];
		}
		for (int j = 1; j < L; ++j) {
			if (~pr[i][j]) {
				sum[i][j] = sum[i][j - 1] + sum[pr[i][j - 1]][j - 1];
			}
		}
	}

	cout << (accumulate(all(dp), Mint(0)) + 1) * mult << "\n";

	return 0;
}