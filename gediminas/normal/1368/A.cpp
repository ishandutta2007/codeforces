#include <bits/stdc++.h>

using namespace std;
/*input
2
1 2 3
5 4 100
*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		long long a, b, n;
		cin >> a >> b >> n;
		int s = 0;

		while (a <= n and b <= n) {
			if (a < b) {
				a += b;
			}
			else {
				b += a;
			}

			s++;
		}

		cout << s << "\n";
	}
}