#include <bits/stdc++.h>

using namespace std;
/*input
5
2 1
19 0
10 2
100 1
1999 0
2 3
1 0
1 0
99 0
1 2

*/

int logas10(long long x) {
	int t = 0;

	while (x >= 10) {
		x /= 10;
		t++;
	}

	return t;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	while (t--) {
		long long a1, p1, a2, p2;
		cin >> a1 >> p1;
		cin >> a2 >> p2;
		p1 += logas10(a1);
		p2 += logas10(a2);

		if (p1 > p2) {
			cout << ">";
		}
		else if (p1 < p2) {
			cout << "<";
		}
		else {
			while (logas10(a1) > logas10(a2)) {
				a2 *= 10;
			}

			while (logas10(a2) > logas10(a1)) {
				a1 *= 10;
			}

			if (a1 > a2) {
				cout << ">";
			}
			else if (a1 < a2) {
				cout << "<";
			}
			else {
				cout << "=";
			}
		}

		cout << "\n";
	}
}