#include <iostream>
#include <vector>

using namespace std;

int main() {
	int k;
	cin >> k;
	int a = k, b = (1 << 17) + k, c = (1 << 17);
	cout << 3 << " " << 3 << endl;
	cout << b << " " << a << " " << 0 << endl;
	cout << c << " " << b << " " << 0 << endl;
	cout << 0 << " " << a << " " << b << endl;
	return 0;
}