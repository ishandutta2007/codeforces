#include <iostream>
#include <vector>

#define ll long long int

using namespace std;

int a, b;

int main() {
	cin >> a >> b;
	if (a == 9 && b == 1) {
		cout << "9 10";
		return 0;
	}
	if (abs(a - b) > 1) {
		cout << "-1";
		return 0;
	}
	if (a < b) {
		cout << a << "9 " << b << "0";
		return 0;
	}
	if (a == b) {
		cout << a << "0 " << b << "1 ";
		return 0;
	}
	
	cout << "-1";
	return 0;
}