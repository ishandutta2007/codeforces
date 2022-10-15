#ifdef DEBUG
	#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

const int ssz = 5032108;
int sieve[ssz] = {};
vector<int> primes;

inline void initSieve() {
	for (int i = 0; i < ssz; i++) {
		sieve[i] = i;
	}
	for (int i = 2; i*i < ssz; i++) {
		if (sieve[i] == i) {
			for (int j = i*i; j < ssz; j += i) {
				if (sieve[j] == j) {
					sieve[j] = i;
				}
			}
		}
	}
}

inline vector<int> divisors(int x) {
	vector<int> res;
	while (x != 1) {
		int q = sieve[x];
		int knt = 0;
		while (x % q == 0) {
			x /= q;
			knt ^= 1;
		}
		if (knt) {
			res.push_back(q);
		}
	}
	return res;
}

inline vector< pair<int, int> > masks(const vector<int> &d) {
	int n = size(d);
	vector< pair<int, int> > res(1 << n);
	for (int i = 0; i < (1 << n); i++) {
		int x = 1;
		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				x *= d[j];
			}
		}
		res[i] = {x, n - __builtin_popcount(i)};
	}
	return res;
}

int main() {
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	
	initSieve();
	
	const int dmax = 7+1;
	const int amax = dmax*2-1;
	
	int n, q; cin >> n >> q;
	
	vector< vector<int> > dp(ssz, vector<int>(dmax, -1));
	vector<int> rng(amax, -1);
	vector< vector<int> > rngs(n);
	
	for (int i = 0; i < n; i++) {
		int val; cin >> val;
		for (auto it: masks(divisors(val))) {
			int x = it.first, val = it.second;
			for (int j = 0; j < dmax; j++) {
				rng[j+val] = max(rng[j+val], dp[x][j]);
			}
			dp[x][val] = max(dp[x][val], i);
		}
		int mx = -1;
		for (int j = 0; j < amax; j++) {
			mx = max(mx, rng[j]);
			rng[j] = mx;
		}
		rngs[i] = rng;
	}
	
	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r; l--; r--;
		int ans = lower_bound(begin(rngs[r]), end(rngs[r]), l) - begin(rngs[r]);
		cout << ans << "\n";
	}
	
	return 0;
}