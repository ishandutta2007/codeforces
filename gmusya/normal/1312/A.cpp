#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, m;
		cin >> n >> m;
		if (n % m)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}