#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <set>

#define ll long long

using namespace std;

set <ll> d;

const ll MAXP = 1e6 + 1;

void find_primes(vector <ll> &pr, vector <ll> &lp) {
	for (ll i = 2; i < MAXP; i++) {
		if (lp[i] == 0) {
			pr.push_back(i);
			lp[i] = i;
		}
		for (ll j = 0; j < pr.size() && pr[j] <= i && pr[j] * i < MAXP; j++)
			lp[pr[j] * i] = pr[j];
	}
}

void solve(vector <ll> &a, ll x, vector <ll> &pr) {
	ll n = a.size();
	ll ans = n;
	x = max(1LL, x);
	for (ll i = 0; i < pr.size(); i++) {
		if (x == 1)
			break;
		if (x % pr[i] == 0) {
			d.insert(pr[i]);
			while (x % pr[i] == 0)
				x /= pr[i];
		}
	}
	if (x > 1)
		d.insert(x);
}

mt19937_64 gen(time(0));

int main() {
	srand(time(0));
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector <ll> pr, lp(MAXP);
	find_primes(pr, lp);
	ll n;
	cin >> n;
	vector <ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	shuffle(a.begin(), a.end(), gen);
	ll it = 125;
	ll ans = n;
	while (it--) {
		ll pos = rand() % a.size();
		solve(a, a[pos], pr);
		solve(a, a[pos] + 1, pr);
		solve(a, a[pos] - 1, pr);
	}
	for (ll p : d) {
		ll cur_cnt = 0;
		for (ll i = 0; i < n; i++) {
			ll z = min(a[i] % p, p - (a[i] % p));
			if (a[i] < p)
				z = p - a[i];
			cur_cnt += z;
		}
		ans = min(ans, cur_cnt);
	}
	cout << ans;
	return 0;
}