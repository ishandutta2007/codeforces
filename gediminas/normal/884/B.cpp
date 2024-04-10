/*input
2 10
1 3
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, x;
	cin >> n >> x;
	long long s = n - 1;

	for (int i = 0; i < n; i++) {
		long long j;
		cin >> j;
		s += j;
	}

	cout << (s == x ? "YES" : "NO");

	return 0;
}