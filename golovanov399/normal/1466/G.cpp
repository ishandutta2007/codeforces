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
	// scanf("%d", &x);
	cin >> x;
	return x;
}

constexpr int mod = 1'000'000'007;

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	cin.sync_with_stdio(false);
	cin.tie(nullptr);

	int n = nxt(), q = nxt();
	string s0, t;
	cin >> s0 >> t;
	const int l = s0.size();

	auto is_good = [&](const string& s, char c, int rem, int per) {
		for (int i = rem; i < (int)s.length(); i += per) {
			if (s[i] != c) {
				return false;
			}
		}
		return true;
	};

	vector<int> p(n + 1, 1);
	for (int i = 1; i <= n; ++i) {
		p[i] = p[i - 1] * 2 % mod;
	}

	vector<vector<int>> next_noneq(n + 1, vector<int>(26, n));
	for (int i = n - 1; i >= 0; --i) {
		next_noneq[i].assign(26, i);
		next_noneq[i][t[i] - 'a'] = next_noneq[i + 1][t[i] - 'a'];
	}
	vector<vector<int>> next_eq(n + 1, vector<int>(26, n));
	for (int i = n - 1; i >= 0; --i) {
		next_eq[i] = next_eq[i + 1];
		next_eq[i][t[i] - 'a'] = i;
	}

	vector<vector<long long>> hash(26, vector<long long>(n + 1, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 26; ++j) {
			hash[j][i + 1] = hash[j][i] * 2;
			if (t[i] == 'a' + j) {
				hash[j][i + 1] += 1;
			}
			hash[j][i + 1] %= mod;
		}
	}

	auto calc = [&](const string& s, int k, int rem) -> int64_t {
		int len = ((int)s.length() + l - rem) / (l + 1);
		if (k < 30 && len >= (1 << k)) {
			return 0;
		}

		int i = 0;
		int per = l + 1;
		while (i < k) {
			if (per > 1e8 && rem < (int)s.length()) {
				if (next_eq[i][s[rem] - 'a'] >= k) {
					return 0;
				}
				i = next_eq[i][s[rem] - 'a'];
			}

			bool g0 = is_good(s, t[i], rem, 2 * per);
			bool g1 = is_good(s, t[i], rem + per, 2 * per);
			if (!g0 && !g1) {
				return 0;
			}
			if (g0 && g1) {
				break;
			}
			if (g0) {
				rem += per;
			}
			per *= 2;
			++i;
		}
		// cerr << k << ": " << i << " " << rem << " mod " << per << "\n";
		if (i == k) {
			return rem >= (int)s.length();
		}
		
		if (rem >= (int)s.length()) {
			return p[k - i];
		}

		len = ((int)s.length() + per - 1 - rem) / per;
		int j = next_noneq[i][s[rem] - 'a'];
		j = min(j, k);

		if (j == k) {
			if (k - i < 30 && (1 << (k - i)) - 1 < len) {
				return 0;
			}
			return (p[j - i] - len + mod) % mod;
		}

		// 2^{k - j} * (2^{j - i} - len + 1)

		// blocks: 2^{j - i} - 1, 2^{j - i + 1} - 1
		// glues: hash[k] - hash[j] * 2^{k - j}

		long long big_blocks = hash[s[rem] - 'a'][k] - hash[s[rem] - 'a'][j] * p[k - j] % mod;
		big_blocks %= mod;
		if (big_blocks < 0) {
			big_blocks += mod;
		}
		long long small_blocks = (p[k - j] - 2 * big_blocks + 2 * mod) % mod;

		long long ans = 0;
		if (j - i >= 30 || (1 << (j - i)) > len) {
			ans += small_blocks * (p[j - i] - len + mod) % mod;
		}
		if (j - i + 1 >= 30 || (1 << (j - i + 1)) > len) {
			ans += big_blocks * (p[j - i + 1] - len + mod) % mod;
		}

		return ans;
	};

	while (q--) {
		int k = nxt();
		string s;
		cin >> s;
		vector<int> mask(l + 1);
		for (int i = 0; i < (int)s.size(); ++i) {
			mask[i % (l + 1)] |= 1 << (s[i] - 'a');
		}
		vector<char> let(l + 1, 0);
		for (int i = 0; i <= l; ++i) {
			if (__builtin_popcount(mask[i]) == 1) {
				let[i] = 'a' + __builtin_ctz(mask[i]);
			}
		}
		long long answer = 0;
		for (int r = 0; r <= l; ++r) {
			bool ok = true;
			for (int i = 0; i <= l && i < (int)s.size(); ++i) {
				if (r + i != l && s0[(r + i) % (l + 1)] != let[i]) {
					ok = false;
					break;
				}
			}
			if (!ok) {
				continue;
			}
			// cerr << s << " " << k << " " << l - r << " --\n";

			answer += calc(s, k, l - r);
		}
		cout << answer % mod << "\n";
	}

	return 0;
}