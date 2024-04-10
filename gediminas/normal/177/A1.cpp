#include <bits/stdc++.h>

using namespace std;
/*input
5
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1

*/
/*input
3
1 2 3
4 5 6
7 8 9

*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	long long s = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			long long t;
			cin >> t;

			if (i == j or j + i == n - 1 or i == n / 2 or j == n / 2) {
				s += t;
			}
		}
	}
	cout << s;
}