#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
	int n, k;
	cin >> n >> k;
	vector <int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		a[i] = c - '0';
	}
	for (int i = 0; i < k; i++)
		b[i] = a[i];
	for (int i = k; i < n; i++)
		b[i] = b[i - k];
	bool tf = true;
	for (int i = 0; i < n; i++) {
		if (a[i] < b[i])
			break;
		if (a[i] > b[i]) {
			tf = false;
			break;
		}
	}
	if (!tf) {
		for (int i = k - 1; i >= 0; i--) {
			if (b[i] < 9) {
				b[i]++;
				break;
			}
			b[i] = 0;
		}
	}
	cout << n << endl;
	for (int i = k; i < n; i++)
		b[i] = b[i - k];
	for (auto now : b)
		cout << now;
	return 0;
}