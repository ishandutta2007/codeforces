#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <char> c(n), d(n);
	vector <int> a(n), b(n);
	for (int i = 0; i < n; i++)
		cin >> c[i];
	for (int i = 0; i < n; i++)
		a[i] = c[i] - '0';
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++)
		cin >> d[i];
	for (int i = 0; i < n; i++)
		b[i] = d[i] - '0';
	sort(b.begin(), b.end());
	int uka = 0, ukb = 0, cnt = 0;
	while (ukb < n) {
		if (a[uka] > b[ukb]) {
			ukb++;
			cnt++;
			continue;
		}
		if (b[ukb] >= a[uka]) {
			ukb++;
			uka++;
		}
	}
	cout << cnt << endl;
	uka = 0, ukb = 0, cnt = 0;
	while (ukb < n) {
		if (a[uka] >= b[ukb]) {
			ukb++;
			continue;
		}
		if (a[uka] < b[ukb]) {
			uka++;
			ukb++;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}