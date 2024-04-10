#include <iostream>
#include <vector>
#include <math.h>

#define ll long long int

using namespace std;

void find_all_divisors(ll n, vector <ll> &divisors) {
	for (ll i = 1; i * i <= n; i++)
		if (n % i == 0)
			divisors.push_back(i);
	ll d = divisors.size();
	if (n / divisors[d - 1] != divisors[d - 1])
		divisors.push_back(n / divisors[d - 1]);
	for (ll i = d - 2; i >= 0; i--)
		divisors.push_back(n / divisors[i]);
}

int main() {
	ll n;
	vector <ll> divisors;
	cin >> n;
	find_all_divisors(n, divisors);
	if (divisors.size() < 3)
		cout << n;
	if (divisors.size() >= 3) {
		bool tf = true;
		for (int i = 1; i < divisors.size() - 1; i++)
			if (divisors[i] % divisors[1] != 0)
				tf = false;
		if (tf)
			cout << divisors[1];
		else
			cout << 1;
	}
	return 0;
}