#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int mod1 = (int)1e9 + 7;
const int mod2 = (int)1e9 + 9;

struct Hash {
	int _1, _2;

	Hash()
		: _1(0), _2(0) {
	}

	Hash(int64_t a, int64_t b)
		: _1(a % mod1), _2(b % mod2) {
	}
};

inline bool operator==(const Hash& a, const Hash& b) {
	return a._1 == b._1 && a._2 == b._2;
}

inline Hash operator+(const Hash& a, const Hash& b) {
	return Hash(a._1 + b._1, a._2 + b._2);
}

inline Hash operator-(const Hash& a, const Hash& b) {
	return Hash(a._1 + mod1 - b._1, a._2 + mod2 - b._2);
}

inline Hash operator*(const Hash& a, int b) {
	return Hash((int64_t)a._1 * b, (int64_t)a._2 * b);
}

inline Hash operator*(const Hash& a, const Hash& b) {
	return Hash((int64_t)a._1 * b._1, (int64_t)a._2 * b._2);
}

const Hash hashPow = {89, 97};

vector<Hash> hashPows;

inline void initHashes(int maxLen) {
	hashPows.resize(maxLen + 1);
	hashPows[0] = Hash(1, 1);
	for (int i = 1; i <= maxLen; i++) {
		hashPows[i] = hashPows[i-1] * hashPow;
	}
}

inline vector<Hash> getHash(const string &s) {
	int n = s.size();
	vector<Hash> hsh(n+1);
	hsh[0] = Hash(0, 0);
	for (int i = 0; i < n; i++) {
		hsh[i+1] = hsh[i] + hashPows[i] * s[i];
	}
	return hsh;
}

inline bool equalSubstrs(const vector<Hash> &a, const vector<Hash> &b,
                         int pA, int pB, int len) {
	Hash hA = a[pA + len] - a[pA];
	Hash hB = b[pB + len] - b[pB];
	if (pA < pB) {
		hA = hA * hashPows[pB - pA];
	} else {
		hB = hB * hashPows[pA - pB];
	}
	return hA == hB;
}

inline int lcp(const vector<Hash> &a, const vector<Hash> &b, int pA, int pB) {
	int maxLenA = (int)a.size() - pA - 1;
 	int maxLenB = (int)b.size() - pB - 1;
	int l = 0, r = min(maxLenA, maxLenB);
	while (l < r) {
		int m = (l + r + 1) / 2;
		if (equalSubstrs(a, b, pA, pB, m)) {
			l = m;
		} else {
			r = m-1;
		}
	}
	return l;
}

int main() {
	initHashes(200000);
	int n; cin >> n;
	string a; cin >> a;
	int m; cin >> m;
	string b; cin >> b;
	int k; cin >> k;
	auto hA = getHash(a);
	auto hB = getHash(b);
	static int dp[131071][33] = {};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j] = INT_MIN;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (dp[i][j] == INT_MIN) {
				continue;
			}
			int pA = i, pB = dp[i][j];
			int theLcp = lcp(hA, hB, pA, pB);
			dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
			dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
			dp[i + theLcp][j+1] = max(dp[i + theLcp][j+1], dp[i][j] + theLcp);
		}
	}
	cout << (dp[n][k] >= m ? "YES" : "NO") << endl;
	return 0;
}