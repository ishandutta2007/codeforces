#include <iostream>
#include <vector>

#define ll long long int

using namespace std;

vector <ll> primes;
vector <ll> d(5000001);

void find_all_primes(ll	n) {
	for (ll i = 2; i <= n; i++) {
		bool tf = true;
		for (ll j = 0; j < primes.size(); j++) {
			if (primes[j] * primes[j] > i)
				break;
			if (i % primes[j] == 0) {
				d[i] = d[i / primes[j]] + 1;
				tf = false;
				break;
			}
		}
		if (tf) {
			d[i] = 1;
			primes.push_back(i);
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	vector <ll> sum(5000000);
	find_all_primes(5000000);
	sum[1] = 0;
	for (ll i = 2; i <= 5000000; i++)
		sum[i] = sum[i - 1] + d[i];
	ll t;
	vector <ll> ans;
	cin >> t;
	while (t--) {
		ll l, r;
		cin >> r >> l;
		ans.push_back(sum[r] - sum[l]);
	}
	for (auto now : ans)
		cout << now << "\n";
	return 0;
}