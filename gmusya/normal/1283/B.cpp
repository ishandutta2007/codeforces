#include <iostream>
#include <vector>

#define ll long long
using namespace std;

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		if (n % k <= k / 2)
			cout << n << endl;
		else
			cout << n / k * k + k / 2 << endl;
	}
	return 0;
}