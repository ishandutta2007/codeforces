#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int c = a[0];
	int sum = 0;
	int sumwithc = c;
	for (int i = 0; i < n; i++) sum += a[i];
	for (int i = 1; i < n; i++) if (c >= a[i] * 2) sumwithc += a[i];
	int k = 1;
	if (2 * sumwithc <= sum) cout << "0";
	else {
		for (int i = 1; i < n; i++) if (c >= a[i] * 2) k++;
		cout << k << endl;
		cout << 1 << " ";
		for (int i = 1; i < n; i++) if (c >= a[i] * 2) cout << i + 1 << " ";
	}
	return 0;
}