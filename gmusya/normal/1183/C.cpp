#include <iostream>
#include <vector>

using namespace std;

long long int min(long long int a, long long int b) {
	long long int k = a;
	if (k > b) k = b;
	return k;
}

int main() {
	long long int q;
	cin >> q;
	vector <long long int> arr(q);
	for (long long int i = 0; i < q; i++) {
		long long int k, n, a, b;
		cin >> k >> n >> a >> b;
		long long int moves1 = (k - 1) / a;
		if (moves1 >= n) arr[i] = n; else {
			long long int moves2 = (k - 1) / b;
			if (moves2 < n) arr[i] = -1; else {
				arr[i] = min (moves1, ((k - 1) - (n * b)) / (a - b));
			}
		}
	}
	for (long long int i = 0; i < q; i++) cout << arr[i] << endl;
	return 0;
}