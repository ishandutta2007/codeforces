#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int n;
	string s;
	cin >> n;
	vector <int> a(n);
	vector <int> b(n);
	vector <vector <int>> c(500);
	cin >> s;
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
	for (int i = 0; i < n; i++) b[i];
	for (int i = 0; i < 500; i++) c[i].resize(n);
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') c[0][i] = 0;
		if (s[i] == '1') c[0][i] = 1;
	}
	for (int i = 1; i <= 499; i++) {
		for (int j = 0; j < n; j++) {
			c[i][j] = (c[i - 1][j] + ((i - b[j] >= 0) && (i - b[j]) % a[j] == 0)) % 2;
		}
	}
	vector <int> d(500);
	for (int i = 0; i <= 499; i++) {
		d[i] = 0;
		for (int j = 0; j < n; j++) {
			d[i] += c[i][j];
		}
	}
	sort(d.begin(), d.end());
	cout << d[499];
	return 0;
}