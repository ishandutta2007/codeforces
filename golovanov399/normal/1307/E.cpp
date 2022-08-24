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

const int mod = 1000000007;
using Mint = Modular<mod>;

const int N = 5555;
bool exists[N][N];

Mint inv[N];

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	inv[1] = 1;
	for (int i = 2; i < N; ++i) {
		inv[i] = Mint(0) - inv[mod % i] * (mod / i);
		assert((inv[i] * i).val == 1);
	}

	int n = nxt(), m = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt() - 1;
	}

	vector<pair<int, int>> cows(m);
	for (int i = 0; i < m; ++i) {
		cows[i].first = nxt() - 1;
		cows[i].second = nxt();
	}

	// a.push_back(n);
	// a.insert(a.begin(), n + 1);
	// cows.push_back({n, 1});
	// cows.push_back({n + 1, 1});
	// n += 2;
	// m += 2;

	for (auto [x, y] : cows) {
		exists[x][y] = true;
	}

	vector<int> left_index(n), right_index(n);
	vector<char> can_be_left(n), can_be_right(n);
	{
		vector<int> cnt(n, 0);
		for (int i = 0; i < n; ++i) {
			left_index[i] = (cnt[a[i]] += 1);
			can_be_left[i] = exists[a[i]][cnt[a[i]]];
		}
	}
	{
		vector<int> cnt(n, 0);
		for (int i = n - 1; i >= 0; --i) {
			right_index[i] = (cnt[a[i]] += 1);
			can_be_right[i] = exists[a[i]][cnt[a[i]]];
		}
	}

	vector<int> pref(n), suf(n);
	for (int i = 0; i < n; ++i) {
		pref[i] = can_be_left[i];
		if (i) {
			pref[i] += pref[i - 1];
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		suf[i] = can_be_right[i];
		if (i < n - 1) {
			suf[i] += suf[i + 1];
		}
	}

	int ans = 0;
	Mint cnt_ways = 1;
	vector<Mint> deg2(n + 1);
	deg2[0] = 1;
	for (int i = 0; i < n; ++i) {
		deg2[i + 1] = deg2[i] * 2;
	}

	auto getForw = [&](int a, int b) -> pair<int, Mint> {
		if (a > b) {
			swap(a, b);
		}
		if (b == 0) {
			return {0, 1};
		} else if (a == 0) {
			return {1, b};
		} else if (b == 1) {
			return {1, 2};
		} else {
			return {2, a * (b - 1)};
		}
	};
	auto getBack = [&](int a, int b) -> pair<int, Mint> {
		if (a > b) {
			swap(a, b);
		}
		if (b == 0) {
			return {0, 1};
		} else if (a == 0) {
			return {1, inv[b]};
		} else if (b == 1) {
			return {1, inv[2]};
		} else {
			return {2, inv[a] * inv[b - 1]};
		}
	};

	auto relax = [&](int& cur, Mint& num_ways, int a, int b, bool pos) {
		auto [cn, mn] = pos ? getForw(a, b) : getBack(a, b);
		if (pos) {
			cur += cn;
			num_ways *= mn;
		} else {
			cur -= cn;
			num_ways *= mn;
		}
	};

	{
		vector<int> left_count(n);
		Mint num_ways = 1;
		int cur = 0;
		for (int i = 0; i < n; ++i) {
			if (can_be_left[i]) {
				relax(cur, num_ways, left_count[a[i]], 0, false);
				left_count[a[i]] += 1;
				relax(cur, num_ways, left_count[a[i]], 0, true);
			} else {
				continue;
			}
			auto tmp = num_ways;
			auto ccur = cur;
			relax(ccur, tmp, left_count[a[i]], 0, false);
			relax(ccur, tmp, 1, 0, true);
			if (ccur > ans) {
				ans = ccur;
				cnt_ways = tmp;
			} else if (ccur == ans) {
				cnt_ways += tmp;
			}
		}
	}
	{
		vector<int> right_count(n);
		Mint num_ways = 1;
		int cur = 0;
		for (int j = n - 1; j >= 0; --j) {
			if (can_be_right[j]) {
				relax(cur, num_ways, 0, right_count[a[j]], false);
				right_count[a[j]] += 1;
				relax(cur, num_ways, 0, right_count[a[j]], true);
			} else {
				continue;
			}
			auto tmp = num_ways;
			auto ccur = cur;
			relax(ccur, tmp, 0, right_count[a[j]], false);
			relax(ccur, tmp, 0, 1, true);
			if (ccur > ans) {
				ans = ccur;
				cnt_ways = tmp;
			} else if (ccur == ans) {
				cnt_ways += tmp;
			}
		}
	}
	{
		vector<int> right_count(n);
		Mint num_ways = 1;
		int cur = 0;
		for (int j = n - 1; j >= 0; --j) {
			if (can_be_right[j]) {
				relax(cur, num_ways, 0, right_count[a[j]], false);
				right_count[a[j]] += 1;
				relax(cur, num_ways, 0, right_count[a[j]], true);
			}
			auto cur1 = cur;
			auto num_ways1 = num_ways;
			vector<int> left_count(n);
			for (int i = 0; i < j; ++i) {
				if (can_be_left[i]) {
					relax(cur, num_ways, left_count[a[i]], right_count[a[i]], false);
					left_count[a[i]] += 1;
					relax(cur, num_ways, left_count[a[i]], right_count[a[i]], true);
				}

				if (!can_be_left[i] || !can_be_right[j]) {
					continue;
				}
				if (a[i] == a[j] && left_index[i] == right_index[j]) {
					continue;
				}
				auto tmp = num_ways;
				auto ccur = cur;
				if (a[i] == a[j]) {
					relax(ccur, tmp, left_count[a[i]], right_count[a[j]], false);
					ccur += 2;
				} else {
					relax(ccur, tmp, left_count[a[i]], right_count[a[i]], false);
					relax(ccur, tmp, 1, 0, true);
					relax(ccur, tmp, left_count[a[j]], right_count[a[j]], false);
					relax(ccur, tmp, 0, 1, true);
					if (right_count[a[i]] - (right_count[a[i]] >= left_count[a[i]])) {
						ccur += 1;
						tmp *= right_count[a[i]] - (right_count[a[i]] >= left_count[a[i]]);
					}
					if (left_count[a[j]] - (left_count[a[j]] >= right_count[a[j]])) {
						ccur += 1;
						tmp *= left_count[a[j]] - (left_count[a[j]] >= right_count[a[j]]);
					}
				}
				// cerr << i << " " << j << ": " << left_count[a[i]] << " " << right_count[a[j]] << " " << ccur << " " << tmp << "\n";
				if (ccur > ans) {
					ans = ccur;
					cnt_ways = tmp;
				} else if (ccur == ans) {
					cnt_ways += tmp;
				}
			}
			cur = cur1;
			num_ways = num_ways1;
		}
	}

	cout << ans << " " << cnt_ways << "\n";

	return 0;
}