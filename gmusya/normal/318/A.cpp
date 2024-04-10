#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	ll n, m;
	cin >> n >> m;
	if (n % 2 == 0) {
		if (m * 2 <= n)
			cout << m * 2 - 1;
		else
			cout << (m - n / 2) * 2;
	}
	else {
		if (m * 2 <= n + 1)
			cout << m * 2 - 1;
		else
			cout << (m - (n + 1) / 2) * 2;
	}
	return 0;
}