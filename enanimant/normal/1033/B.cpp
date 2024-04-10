// October 7, 2018
// http://codeforces.com/contest/1033/problem/B

/*

*/


#include <bits/stdc++.h>

using namespace std;


vector<int> primes;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG


	vector<int> sieve((int) 1e6 + 1, 0);
	for (int i = 2; i * i <= (int) 1e6; i++) {
		if (sieve[i]) continue;
		for (int j = i * i; j <= (int) 1e6; j += i) {
			sieve[j] = i;
		}
	}
	for (int i = 2; i <= (int) 1e6; i++) {
		if (sieve[i] == 0) primes.push_back(i);
	}

	int t;
	cin >> t;
	while (t--) {
		long long a, b;
		cin >> a >> b;
		if (a - b > 1) {
			cout << "NO\n";
			continue;
		}
		bool prime = true;
		if (binary_search(primes.begin(), primes.end(), a + b)) {
			cout << "YES\n";
			continue;
		}
		for (int p : primes) {
			if ((a + b) % p == 0) {
				cout << "NO\n";
				prime = false;
				break;
			}
		}
		if (prime) cout << "YES\n";
	}


	return 0;
}