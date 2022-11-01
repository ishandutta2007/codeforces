#include <iostream>

#define ll long long 

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		ll x;
		cin >> x;
		if (x > 14 && x % 14 > 0 && x % 14 < 7)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}