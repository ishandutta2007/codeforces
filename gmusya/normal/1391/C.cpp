#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

const ll MOD = 1e9 + 7;

int main() {
	ll n;
	cin >> n;
	ll p = 1;
	for (int i = 1; i < n; i++)
		p = (p * 2) % MOD;
	ll f = 1;
	for (int i = 2; i <= n; i++)
		f = (f * i) % MOD;
	cout << (f - p + MOD) % MOD;
	return 0;
}