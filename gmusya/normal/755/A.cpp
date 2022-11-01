#include <iostream>
#include <vector>
#include <set>

#define ll long long int

using namespace std;

void find_all_primes(ll	n, set <ll> &primes) {
	for (ll i = 2; i <= n; i++) {
		bool tf = true;
		for (auto x : primes) {
			if (x * x > i)
				break;
			if (i % x == 0) {
				tf = false;
				break;
			}
		}
		if (tf)
			primes.insert(i);
	}
}

int main() {
	set <ll> primes;
	find_all_primes(1000000, primes);
	ll n, m = 1;
	cin >> n;
	while (primes.find(n * m + 1) != primes.end())
		m++;
	cout << m;
	return 0;
}