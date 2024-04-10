// September 23, 2018
// http://codeforces.com/contest/1058/problem/D

/*

*/


#include <bits/stdc++.h>

using namespace std;


long long n, m;
int k;
vector<int> primes;

void gen_primes(int mp) {
	vector<int> sieve(mp + 1, 0);
	for (int x = 2; x * x <= mp; x++) {
		if (sieve[x]) continue;
		for (int i = x * x; i <= mp; i += x) {
			sieve[i] = x;
		}
	}
	for (int i = 2; i <= mp; i++) {
		if (sieve[i] == 0) {
			primes.push_back(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG)


	cin >> n >> m >> k;
	if (2 * m * n % k != 0) {
		cout << "NO\n";
		return 0;
	}
	gen_primes((int) sqrt(1e9));

	long long a = 2 * n, b = m;
	for (int p : primes) {
		while (k % p == 0) {
			k /= p;
			if (a % p == 0) a /= p;
			else if (b % p == 0) b /= p;
			else {
				assert(p == 2);
				k *= 2;
				break;
			}
		}
	}

	bool even = (k % 2 == 0);
	if (even) {
		k /= 2;
	}
	if (a % k == 0) a /= k;
	else b /= k;
	k = 1;
	if (even) {
		k *= 2;
	}

	if (k == 2) {
		if (a * 2 <= n) a *= 2;
		else b *= 2;
	}
	while (a % 2 == 0 && a > n) {
		a /= 2;
		b *= 2;
	}
	if (a > n || b > m) {
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";
	cout << "0 0\n";
	cout << a << " 0\n";
	cout << "0 " << b << '\n';


	return 0;
}