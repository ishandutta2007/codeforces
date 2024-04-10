#include <bits/stdc++.h>

using namespace std;
/*input
3
1 3 1

*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	long long sum = 0, ma = 0;

	for (int i = 0; i < n; ++i) {
		long long x;
		cin >> x;
		sum += x;
		ma = max(ma, x);
	}

	cout << ma *n - sum;
}