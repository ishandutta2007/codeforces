#include <bits/stdc++.h>

using namespace std;
/*input
4 3

*/
/*input
5 5
*/
/*input
8 4
*/
long long inf = 10000000000;

long long sum(long long a) {
	return a * (a + 1) / 2;
}

long long sum(long long a, long long b) {
	return sum(b) - sum(a);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	long long n, k;
	cin >> n >> k;
	n--, k--;

	if (n > k * (k + 1) / 2) {
		cout << -1;
		exit(0);
	}

	long long mi = 0, ma = k;

	while (mi < ma) {
		long long mid = (mi + ma + 1) / 2;

		if (sum(mid, k) < n) {
			ma = mid - 1;
		}
		else {
			mi = mid;
		}
	}
	cout << k - mi << endl;
}