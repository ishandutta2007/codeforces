#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector <char> a;

int main() {
	cin >> n >> k;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	if (n == 1 && k == 1) cout << 0;
	else {
		for (int i = 0; i < n && k > 0; i++) {
			if (i == 0 && a[i] != '1') {
				k--;
				a[i] = '1';
			}
			if (i != 0 && a[i] != '0') {
				k--;
				a[i] = '0';
			}
		}
		for (int i = 0; i < n; i++) cout << a[i];
	}

	return 0;
}