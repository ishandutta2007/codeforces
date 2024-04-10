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

using ull = unsigned long long;

const int mod = 998244353;

const int M = 35;
const int K = 19;
long long dp[M + 1][1 << (M - K)];

ull reshuffle(ull x, const vector<ull>& basis_bits) {
	ull res = 0;
	for (int i = 0, j = 0, cur = basis_bits.size(); i < M; ++i) {
		if (j < (int)basis_bits.size() && (1ull << i) == basis_bits[j]) {
			++j;
		} else {
			if (x & (1ull << i)) {
				res |= 1ull << cur;
			}
			++cur;
		}
	}
	for (int i = 0; i < (int)basis_bits.size(); ++i) {
		if (x & basis_bits[i]) {
			res |= 1ull << i;
		}
	}
	return res;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt();
	vector<ull> a(n);
	for (int i = 0; i < n; ++i) {
		scanf("%llu", &a[i]);
	}
	vector<ull> basis_bits;
	for (int col = 0, row = 0; col < m; ++col) {
		const ull b = 1ull << col;
		for (int i = row; i < n; ++i) {
			if (a[i] & b) {
				swap(a[i], a[row]);
				break;
			}
		}
		if (!(a[row] & b)) {
			continue;
		}
		basis_bits.push_back(b);
		for (int i = row + 1; i < n; ++i) {
			if (a[i] & b) {
				a[i] ^= a[row];
			}
		}
		++row;
	}
	long long mult = 1;
	while (!a.empty() && !a.back()) {
		a.pop_back();
		mult = mult * 2 % mod;
	}
	int sz = a.size();
	if (sz <= K) {
		vector<long long> ans(m + 1);
		function<void(int, ull)> rec = [&](int i, ull mask) {
			if (i == sz) {
				ans[__builtin_popcountll(mask)] += 1;
			} else {
				rec(i + 1, mask);
				rec(i + 1, mask ^ a[i]);
			}
		};
		rec(0, 0);
		for (auto x : ans) {
			cout << x * mult % mod << " ";
		}
		cout << "\n";
		return 0;
	}

	for (int i = sz - 1; i >= 0; --i) {
		for (int j = i - 1; j >= 0; --j) {
			if (a[j] & basis_bits[i]) {
				a[j] ^= a[i];
			}
		}
	}
	for (auto& x : a) {
		x = reshuffle(x, basis_bits);
	}
	dp[0][0] = 1;
	for (int i = 0; i < sz; ++i) {
		ull x = a[i] >> sz;
		for (int taken = i; taken >= 0; --taken) {
			for (int j = 0; j < (1 << (M - K)); ++j) {
				dp[taken + 1][j ^ x] += dp[taken][j];
			}
		}
	}
	vector<long long> ans(m + 1);
	for (int i = 0; i <= sz; ++i) {
		for (int j = 0; j < (1 << (M - K)); ++j) {
			ans[i + __builtin_popcount(j)] += dp[i][j];
		}
	}
	for (auto x : ans) {
		cout << x % mod * mult % mod << " ";
	}
	cout << "\n";

	return 0;
}