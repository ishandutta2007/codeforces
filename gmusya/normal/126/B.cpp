#include <iostream>
#include <vector>
#include <string>
#define ll unsigned long long
#define MOD1 (ll) 655360001
#define MOD2 (ll) 562448657
#define PRIME (ll) 1000003

using namespace std;

struct triplet {
	ll first, second, len;
};

ll n;
string a;
vector <pair <ll, ll>> has;
vector <pair <ll, ll>> power_prime(1e6 + 5);

void reading() {
	cin >> a;
	n = a.size();
	has.resize(n);
}
void creating_power_prime() {
	power_prime[0].first = 1;
	power_prime[0].second = 1;
	for (ll i = 1; i < 1e6 + 2; i++) {
		power_prime[i].first = (power_prime[i - 1].first * PRIME) % MOD1;
		power_prime[i].second = (power_prime[i - 1].second * PRIME) % MOD2;
	}
}
void creating_hashes() {
	has[0].first = a[0] - 'a' + 1;
	has[0].second = a[0] - 'a' + 1;
	for (ll i = 1; i < n; i++) {
		has[i].first = (has[i - 1].first + ((a[i] - 'a' + 1) * power_prime[i].first) % MOD1) % MOD1;
		has[i].second = (has[i - 1].second + ((a[i] - 'a' + 1) * power_prime[i].second) % MOD2) % MOD2;
	}
}
int main() {
	vector <triplet> good;
	reading();
	creating_power_prime();
	creating_hashes();
	if (n < 3) {
		cout << "Just a legend";
		return 0;
	}
	for (ll i = 0; i < n - 2; i++)
		if ((has[i].first * power_prime[n - i - 1].first) % MOD1 == (MOD1 + has[n - 1].first - has[n - i - 2].first) % MOD1 && (has[i].second * power_prime[n - i - 1].second) % MOD2 == (has[n - 1].second + MOD2 - has[n - i - 2].second) % MOD2)
			good.push_back({ has[i].first, has[i].second, i + 1});
	if (good.size() == 0) {
		cout << "Just a legend";
		return 0;
	}
	string s;
	for (ll i = 1; i < a.size() - 1; i++)
		s += a[i];
	vector <pair <ll, ll>> new_has(s.size());
	new_has[0].first = s[0] - 'a' + 1;
	new_has[0].second = s[0] - 'a' + 1;
	for (ll i = 1; i < s.size(); i++) {
		new_has[i].first = (new_has[i - 1].first + ((s[i] - 'a' + 1) * power_prime[i].first) % MOD1) % MOD1;
		new_has[i].second = (new_has[i - 1].second + ((s[i] - 'a' + 1) * power_prime[i].second) % MOD2) % MOD2;
	}
	ll l = 0, r = good.size() - 1;
	bool tf;
	ll cnt = 0;
	while (l != r || cnt < 2) {
		ll m = (l + r) / 2;
		tf = false;
		if (good[m].first == new_has[good[m].len - 1].first && good[m].second == new_has[good[m].len - 1].second)
			tf = true;
		for (ll i = 0; i < s.size() - good[m].len; i++)
			if (((good[m].first * power_prime[i + 1].first) % MOD1 == (MOD1 + new_has[i + good[m].len].first - new_has[i].first) % MOD1) && (good[m].second * power_prime[i + 1].second) % MOD2 == (MOD2 + new_has[i + good[m].len].second - new_has[i].second) % MOD2)
				tf = true;
		if (l == r)
			break;
		if (!tf) 
			r = m;
		else 
			l = m + 1;
		if (l == r)
			cnt++;	
	}
	if (l == 0 && !tf) {
		cout << "Just a legend";
		return 0;
	}
	if (l >= good.size() - 1 && tf)
		for (ll i = 0; i < good[good.size() - 1].len; i++)
			cout << a[i];
	else
		for (ll i = 0; i < good[l - 1].len; i++)
			cout << a[i];
	return 0;
}