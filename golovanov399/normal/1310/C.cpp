#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline long long nxt() {
	long long x;
	cin >> x;
	return x;
}

vector<int> getZ(const string& s) {
	int n = s.length();
	vector<int> z(n);
	z[0] = n;
	int rightmost = -1;
	for (int i = 1; i < n; ++i) {
		if (rightmost > -1 && i < rightmost + z[rightmost]) {
			z[i] = z[i - rightmost];
		}
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
			++z[i];
		}
	}
	return z;
}

struct Substring {
	int pos;
	int len;
};

void remin(int& x, int y) {
	x = min(x, y);
}

void add(long long& x, long long y, long long k) {
	x += y;
	if (x > k) {
		x = k + 1;
	}
}

int main() {
	int n = nxt(), m = nxt();
	long long k = nxt();
	string s;
	cin >> s;

	vector<vector<int>> dp(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i) {
		auto z = getZ(s.substr(i));
		copy(all(z), dp[i].begin() + i);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			dp[i][j] = dp[j][i];
		}
	}

	auto cmp = [&](const Substring& fst, const Substring& snd) {
		const int l = dp[fst.pos][snd.pos];
		if (min(fst.len, snd.len) <= l) {
			return fst.len < snd.len;
		} else {
			return s[fst.pos + l] < s[snd.pos + l];
		}
	};

	vector<Substring> all_positions;
	for (int i = 0; i < n; ++i) {
		for (int l = 1; i + l <= n; ++l) {
			all_positions.push_back({i, l});
		}
	}
	sort(all(all_positions), cmp);
	// for (auto [pos, len] : all_positions) {
	// 	cerr << s.substr(pos, len) << "\n";
	// }
	int l = 0, r = (int)all_positions.size();
	while (r > l + 1) {
		int mid = (l + r) / 2;
		vector<int> suf(n, n + 1);
		for (int i = mid; i < (int)all_positions.size(); ++i) {
			remin(suf[all_positions[i].pos], all_positions[i].pos + all_positions[i].len);
		}
		vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
		vector<vector<long long>> pdp(m + 1, vector<long long>(n + 1, 0));
		dp[0][n] = pdp[0][n] = 1;
		for (int i = n - 1; i >= 0; --i) {
			if (suf[i] <= n) {
				for (int j = 0; j < m; ++j) {
					add(dp[j + 1][i], pdp[j][suf[i]], k);
				}
			}
			for (int j = 0; j <= m; ++j) {
				pdp[j][i] = pdp[j][i + 1];
				add(pdp[j][i], dp[j][i], k);
			}
		}
		// cerr << s.substr(all_positions[mid].pos, all_positions[mid].len) << ": " << dp[m][0] << "\n";
		if (dp[m][0] < k) {
			r = mid;
		} else {
			l = mid;
		}
	}
	cout << s.substr(all_positions[l].pos, all_positions[l].len) << "\n";

	return 0;
}