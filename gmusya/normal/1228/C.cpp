#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define ll long long int

ll binpow(ll a, ll n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return (binpow(a, n - 1)) % 1000000007 * (a % 1000000007) % 1000000007;
	else {
		ll b = (binpow(a, n / 2) % 1000000007);
		return ((b % 1000000007) * (b % 1000000007)) % 1000000007;
	}
}

set <ll> s;

void find(ll n, ll div) {
	if (n == 1) return;
	if (div * div > n) {
		s.insert(n);
		return;
	}
	if (n%div == 0)
	{
		s.insert(div);
		find(n / div, div);
	}
	else
		if (div == 2)
			find(n, div + 1);
		else
			find(n, div + 2);
}
int main() {
	ll n, x;
	ll ans = 0;
	cin >> x >> n;
	find(x, 2);
	vector <ll> kek;
	for (auto now : s) {
		ll r = 0;
		ll z = now;
			while (now <= n) {
				r += n / now;
				if (n / now < z) break;
				now = now*z;
			}
		kek.push_back(r);
	}
	vector <ll> lul;
	for (auto now : s) lul.push_back(now);
	vector <ll> answer(s.size());
	for (int i = 0; i < s.size(); i++) {
		answer[i] = (binpow(lul[i], kek[i])) % 1000000007;
	}
	ll an = 1;
	for (int i = 0; i < s.size(); i++) an = ((an % 1000000007) * (answer[i] % 1000000007)) % 1000000007;
	cout << an << endl;
	return 0;
}