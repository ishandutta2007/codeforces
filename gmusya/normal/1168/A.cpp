#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int l = 0, r = m;
	while (l != r) {
		int x = (l + r) / 2;
		bool tf = true;
		int last = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] + x >= m && (a[i] + x) % m >= last)
				continue;
			if (a[i] >= last) {
				last = a[i];
				continue;
			}
			if (a[i] + x < last) {
				tf = false;
				break;
			}
		}
		if (!tf)
			l = x + 1;
		else
			r = x;
	}
	cout << l;
	return 0;
}