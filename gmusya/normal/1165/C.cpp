#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, l, z;
	l = 0;
	z = 0;
	cin >> n;
	vector <char> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n - 1; i++) {
		if (a[i] == a[i + 1] && (i - l) % 2 == 0) {
			l++;
		}
		else {
			b[z] = a[i];
			z++;
		}
	}
	if ((n - l) % 2 == 0) {
		cout << l << endl;
		for (int i = 0; i < n - l - 1; i++) cout << b[i];
		cout << a[n - 1];
	}
	else {
		cout << l + 1 << endl;
		for (int i = 0; i < n - l - 1; i++) cout << b[i];
	}
	return 0;	
}