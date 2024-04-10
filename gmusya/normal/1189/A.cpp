#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	int sum0 = 0, sum1 = 0;
	for (int i = 0; i < n; i++) {
		char x;
		cin >> x;
		if (x == '1') {
			a[i] = 1;
			sum1++;
		}
		if (x == '0') {
			a[i] = 0;
			sum0++;
		}
	}
	if (sum1 != sum0) {
		cout << "1" << endl;
		for (int i = 0; i < n; i++) cout << a[i];
	}
	if (sum1 == sum0) {
		cout << "2" << endl;
		cout << a[0] << " ";
		for (int i = 1; i < n; i++) cout << a[i];
	}
	return 0;
}