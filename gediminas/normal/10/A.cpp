#include <bits/stdc++.h>

using namespace std;
/*input
1 3 2 1 5 10
0 10
*/
/*input
2 8 4 2 5 10
20 30
50 100
*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	long long n, p1, p2, p3, t2, t3;
	cin >> n >> p1 >> p2 >> p3 >> t2 >> t3;
	int l[n], r[n];

	for (int i = 0; i < n; ++i) {
		cin >> l[i] >> r[i];
	}

	long long ans = 0;

	for (int i = 0; i < n; ++i) {
		ans += (r[i] - l[i]) * p1;
	}

	for (int i = 1; i < n; ++i) {
		long long t = l[i] - r[i - 1];
		ans += min(t2, t) * p1;
		t = max(0ll, t - t2);
		ans += min(t3, t) * p2;
		t = max(0ll, t - t3);
		ans += t * p3;
	}

	cout << ans;
}