#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	vector <int> d(n + 1, 1e9);
	d[0] = -1e9;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
		if (d[j - 1] < a[i] && a[i] < d[j])
			d[j] = a[i];
	}
	for (int i = n; i >= 0; i--) 
		if (d[i] != 1e9) {
			cout << i;
			return 0;
		}
	return 0;
}