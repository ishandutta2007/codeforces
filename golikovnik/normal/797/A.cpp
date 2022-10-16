#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10); cout << fixed;
	int n, k;
	cin >> n >> k;
	vector<int> factorization;
	for (int p = 2; p * p <= n; ++p) {
		while (n % p == 0) {
			n /= p;
			factorization.push_back(p);
		}
	}	
	if (n > 1) {
		factorization.push_back(n);
	}
	int nfactors = szof(factorization);
	if (nfactors < k) {
		puts("-1");
		return 0;
	}
	while (nfactors > k) {
		factorization[nfactors - 2] *= factorization[nfactors - 1];
		--nfactors;
	}
	for (int i = 0; i < nfactors; ++i) {
		if (i) cout << " ";
		cout << factorization[i];
	}
	return 0;	
}