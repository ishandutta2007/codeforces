#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	vector <int> b(n);
	for (int i = 0; i < n; i++)
		b[a[i]] = i;
	reverse(b.begin(), b.end());
	vector <int> m(n);
	m[0] = b[0];
	for (int i = 1; i < n; i++)
		m[i] = max(m[i - 1], b[i]);
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j < n && m[j] == i) {
			cout << n - j << " ";
			j++;
		}
		cout << endl;
	}
	return 0;
}