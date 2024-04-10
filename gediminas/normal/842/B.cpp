/*input
8 4
7
7 8 1
-7 3 2
0 2 1
0 -2 2
-3 -3 1
0 6 2
5 3 1
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	long long r, c;
	cin >> r >> c;

	int n;
	cin >> n;
	int ats = 0;

	for (int i = 0; i < n; i++) {
		long long x, y, t;
		cin >> x >> y >> t;

		if (sqrtl(x * x + y * y) - t >= r - c and sqrtl(x * x + y * y) + t <= r){
			ats++;
		}
	}

	cout << ats;


	return 0;
}