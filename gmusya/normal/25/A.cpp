#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, cnt = 0;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cnt += a[i] % 2;
	if (cnt == 1) {
		for (int i = 0; i < n; i++)
			if (a[i] % 2 == 1) {
				cout << i + 1;
				return 0;
			}
	}
	else {
		for (int i = 0; i < n; i++)
			if (a[i] % 2 == 0) {
				cout << i + 1;
				return 0;
			}
	}
	return 0;
}