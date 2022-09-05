#include <iostream>

using namespace std;

int main() {
	int a, b, c, d, e;
	
	cin >> a >> b >> c >> d >> e;
	int n = a + b + c + d + e;
	
	if (n % 5 != 0 || n == 0) {
		cout << "-1" << endl;
	} else {
		cout << (n / 5) << endl;
	}
	
	return 0;
}