#include <iostream>
#include <vector>

using namespace std;

int main() {
	int q;
	cin >> q;
	vector <int> arr(q);
	for (int i = 0; i < q; i++) {
		int n, k;
		cin >> n >> k;
		vector <int> a(n);
		for (int j = 0; j < n; j++) cin >> a[j];
		int min = a[0];
		int max = a[0];
		for (int j = 0; j < n; j++) {
			if (a[j] < min) min = a[j];
			if (a[j] > max) max = a[j];
		}
		if (max - min > 2 * k) arr[i] = -1; else arr[i] = min + k;
	}
	for (int i = 0; i < q; i++) cout << arr[i] << endl;
	return 0;
}