/*input
4 8 2
1 1 1 7

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, k, x;
	cin >> n >> k >> x;
	long long sum = 0;

	for (int i = 0; i < n - k; i++) {
		int a;
		cin >> a;
		sum += a;
	}

	for (int i = 0; i < k and i < n; i++) {
		int a;
		cin >> a;
		sum += min(a, x);
	}

	cout << sum;

	return 0;
}