#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		ll d = 2;
		while (n % d) d++;
		cout << n + d + (k - 1) * 2 << '\n';
	}
	return 0;
}