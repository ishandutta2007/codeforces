#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int q;
	cin >> q;
	vector <int> arr(q);
	for (int i = 0; i < q; i++) {
		int n;
		cin >> n;
		vector <int> a(n), b(n);
		for (int j = 0; j < n; j++) {
			cin >> a[j];
			b[a[j] - 1]++;
		}
		sort(b.begin(), b.end());
		int max = b[n - 1];
		int sum = 0;
		for (int i = n - 1; i >= 0; i--) if (b[i] > 0 && max > 0) {
			sum += min (b[i], max);
			max = min (b[i], max) - 1;
		}
		arr[i] = sum;
	}
	for (int i = 0; i < q; i++) cout << arr[i] << endl;
		return 0;
}