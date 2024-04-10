#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<pair<pair<vector<int>, int>, int>, int> cache;
ll d;

/*int ways(vector<int> primes, int lo) {
	if (numbersLeft == 0) {
		if (sz(primes) == 0)
			return 1;
		else
			return 0;
	}
	auto key = make_pair(make_pair(primes, lo), numbersLeft);
	if (cache.count(key))
		return cache[key];
	int res = 0;
	rep(i,0,1<<sz(primes)) {
		rrep(j,sz(primes)-1,0) {
			if (primes[j] == primes[j+1] && !(i&(1<<j)) && (i&(1<<(j+1)))) {
				i += (1<<j);
			}
		}
		int prod = 1;
		rep(j,0,sz(primes)) {
			if (i&(1<<j))
				prod *= primes[j];
		}
		if (prod < lo)
			continue;
		if (prod%d == 0)
			continue;
		vector<int> newPrimes;
		rep(j,0,sz(primes)) {
			if (!(i&(1<<j)))
				newPrimes.push_back(primes[j]);
		}
		res += ways(newPrimes, prod, numbersLeft-1);		
		if (res >= 2) {
			cache[key] = 2;
			return 2;
		}
	}
	cache[key] = res;
	return res;
}*/

void solve() {
	ll x;
	cin >> x >> d;
	auto xorig = x;
	int n = 0;
	while (x%d == 0) {
		x /= d;
		++n;
	}
	bool isDPrimePower = true;
	bool isDPrime = true;
	int exponent = 0;
	int xexponent = 0;
	for (int i = 2; i*i <= d; i++ ) {
		if (d%i == 0) {
			int e = d;
			while (e%i == 0) {
				e /= i;
				exponent++;
			}
			e = xorig;
			while (e%i == 0) {
				e /= i;
				xexponent++;
			}
			isDPrimePower = (e == 1);
			isDPrime = false;
			break;
		}
	}
	vector<int> primes;
	rep(i,2,1e9) {
		while (x%i == 0) {
			primes.push_back(i);
			x /= i;
		}
		if (i*i > x) {
			if (x > 1)
				primes.push_back(x);
			break;
		}
	}
	if (n == 1)
		cout << "NO" << endl;
	else if (sz(primes) >= 2)
		cout << "YES" << endl;
	else if (isDPrimePower) {
		if (isDPrime) {
			cout << "NO" << endl;
		} else if ((2*exponent-1)*(n-1) >= xexponent) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	else {
		if (n >= 3)
			cout << "YES" << endl;
		else {
			cout << "NO" << endl;
		}
	}
	/*int ans = ways(primes, 0, n);
	if (ans >= 2)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;*/
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	while (T--)
		solve();
}