#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}

vector <ll> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		ll p, q, b;
		cin >> p >> q >> b;
		ll g = gcd(p, q);
		p /= g;
		q /= g;
		for (int i = 0; i < primes.size(); ++i) {
			if (q % primes[i] == 0 && b % primes[i] == 0) {
				while (q % primes[i] == 0) q /= primes[i];
				while (b % primes[i] == 0) b /= primes[i];
			}
		}
		ll x = gcd(q, b);
		while (x != 1) {
			q /= x;
			x = gcd(q, b);
		}
		if (q == 1) {
			cout << "Finite\n";
		}
		else {
			cout << "Infinite\n";
		}
	}
}