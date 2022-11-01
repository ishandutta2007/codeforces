#include <iostream>
#include <vector>

#define ll long long 

using namespace std;

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll a, b, n, s;
		cin >> a >> b >> n >> s;
		if (a * n + b < s || (s % n > b))
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}