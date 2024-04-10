#include <iostream>
#include <vector>
#include <map>

using namespace std;

inline int64_t normalize(int64_t v) {
	for (int64_t i = 2; i*i <= v; i++) {
		while (v % (i*i) == 0) {
			v /= i*i;
		}
	}
	return v;
}

int main() {
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	
	int k; cin >> k;
	map<int, int> knt;
	for (int i = 0; i < k; i++) {
		int64_t v; cin >> v;
		knt[normalize(v)]++;
	}
	
	vector<int> a;
	for (auto it: knt) {
		a.push_back(it.second);
	}
	int n = a.size();
	
	const int mod = (int)1e9 + 7;
	static int64_t C[400][400] = {},  F[400] = {}, dp[400][400] = {};
	
	F[0] = 1;
	for (int i = 1; i <= k+1; i++) {
		F[i] = (F[i-1] * i) % mod;
	}
	C[0][0] = 1;
	for (int i = 1; i <= k+1; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++) {
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
		}
	}
	
	dp[0][0] = 1;
	int soom = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= soom; j++) {
			for (int k = 1; k <= a[i]; k++) {
				for (int l = 0; l <= k && l <= j; l++) {
					int64_t &val = dp[i+1][j-l+a[i]-k];
					val += dp[i][j] * C[soom-j+1][k-l] % mod * C[j][l] % mod * F[a[i]] % mod * C[a[i]-1][k-1];
					val %= mod;
				}
			}
		}
		soom += a[i];
	}
	
	cout << dp[n][0] << endl;
	return 0;
}