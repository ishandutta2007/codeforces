#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	ll x, s;
	cin >> x >> s;
	if (x > s) {
		cout << "-1";
		return 0;
	}
	if (x == 0 && s == 0) {
		cout << "0";
		return 0;
	}
	if ((x + s) % 2) {
		cout << "-1";
		return 0;
	}
	if (x == 0) {
		cout << 2 << endl;
		cout << s / 2 << " " << s / 2 << endl;
		return 0;
	}
	if (x == s) {
		cout << 1 << endl;
		cout << x << endl;
		return 0;
	}
	ll n1 = x;
	ll n2 = (s - x) / 2;
	if ((n1 & n2) == 0LL) {
		cout << 2 << endl;
		cout << n1 + n2 << " " << n2;
		return 0;
	}
	cout << 3 << endl;
	cout << n1 << " " << n2 << " " << n2 << endl;
	return 0;
}