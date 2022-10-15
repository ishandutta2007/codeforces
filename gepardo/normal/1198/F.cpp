#include <iostream>
#include <random>
#include <vector>
#include <ctime>
#include <set>

using namespace std;

inline vector<int> getPrimes(int x) {
	vector<int> res;
	for (int i = 2; i*i <= x; ++i) {
		if (x % i == 0) {
			res.push_back(i);
			while (x % i == 0) {
				x /= i;
			}
		}
	}
	if (x != 1) {
		res.push_back(x);
	}
	return res;
}

inline int intToMask(int val, vector<int> primes) {
	int res = 0;
	for (int i = 0; i < int(primes.size()); ++i) {
		if (val % primes[i] == 0) {
			res |= 1 << i;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	static int dp[512][512] = {}, p1[512][512] = {}, p2[512][512] = {}, val[512][512] = {};
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	mt19937_64 rnd(42);
	clock_t tiempo = clock();
	while (clock() - tiempo < 0.3 * CLOCKS_PER_SEC) {
		int l, r;
		do {
			l = rnd() % n;
			r = rnd() % n;
		} while (l == r);
		auto lp = getPrimes(v[l]), rp = getPrimes(v[r]);
		vector<int> indices;
		set<int> pr(begin(lp), end(lp));
		pr.insert(begin(rp), end(rp));
		vector<int> p(begin(pr), end(pr));
		int psz = p.size();
		const int k = 9;
		vector<int> knt(psz);
		for (int i = 0; i < n; ++i) {
			if (i == l || i == r) {
				continue;
			}
			bool ok = false;
			for (int j = 0; j < psz; ++j) {
				if (knt[j] < 2*k && v[i] % p[j] != 0) {
					ok = true;
					break;
				}
			}
			if (ok) {
				for (int j = 0; j < psz; ++j) {
					knt[j] += v[i] % p[j] != 0;
				}
				indices.push_back(i);
			}
		}
		int kk = indices.size();
		int lsz = lp.size(), rsz = rp.size();
		for (int i = 0; i < (1 << lsz); ++i) {
			for (int j = 0; j < (1 << rsz); ++j) {
				dp[i][j] = -1;
			}
		}
		dp[(1 << lsz) - 1][(1 << rsz) - 1] = 0;
		for (int i = 0; i < kk; ++i) {
			if (dp[0][0] >= 0) {
				break;
			}
			int lm = intToMask(v[indices[i]], lp);
			int rm = intToMask(v[indices[i]], rp);
			for (int j = 0; j < (1 << lsz); ++j) {
				for (int k = 0; k < (1 << rsz); ++k) {
					if (dp[j][k] < 0) {
						continue;
					}
					if (dp[j&lm][k] < 0) {
						dp[j&lm][k] = i;
						p1[j&lm][k] = j;
						p2[j&lm][k] = k;
						val[j&lm][k] = 1;
					}
					if (dp[j][k&rm] < 0) {
						dp[j][k&rm] = i;
						p1[j][k&rm] = j;
						p2[j][k&rm] = k;
						val[j][k&rm] = 2;
					}
				}
			}
		}
		if (dp[0][0] < 0) {
			continue;
		}
		vector<int> res(n, 1);
		res[l] = 1; res[r] = 2;
		{
			int j = 0, k = 0;
			while (j != (1 << lsz) - 1 || k != (1 << rsz) - 1) {
				int i = dp[j][k];
				int nj = p1[j][k], nk = p2[j][k];
				res[indices[i]] = val[j][k];
				j = nj; k = nk;
			}
			cout << "YES\n";
			for (int i = 0; i < n; ++i) {
				cout << res[i] << " ";
			}
			cout << "\n";
		}
		return 0;
	}
	cout << "NO\n";
	return 0;
}