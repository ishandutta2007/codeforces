#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		int kek;
		cin >> kek;
		if (kek >= 0) a[i] = -kek - 1;
		if (kek < 0) a[i] = kek;
	}

	if (n % 2 == 1) {
		int min = a[0], id = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] < min) {
				min = a[i];
			}
		}
		for (int i = 0; i < n; i++) {
			if (a[i] == min) {
				a[i] = -a[i] - 1;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	return 0;
}