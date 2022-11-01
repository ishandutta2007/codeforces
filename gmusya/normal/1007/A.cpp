#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n), b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++)
		b[i] = a[i];
	int uka = 0, ukb = 0;
	int cnt = 0;
	while (uka < n) {
		if (a[uka] <= b[ukb]) {
			uka++;
			continue;
		}
		if (a[uka] > b[ukb]) {
			uka++;
			ukb++;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}