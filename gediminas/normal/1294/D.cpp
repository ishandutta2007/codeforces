#include <bits/stdc++.h>

using namespace std;
/*input
7 3
0
1
2
2
0
0
10
*/
/*input
4 3
1
2
1
2
*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	long long q, x;
	cin >> q >> x;
	map<long long, int> a;
	long long dab = 0;

	long long sk = 0;

	while (q--) {
		long long t;
		cin >> t;
		a[t % x]++;

		while (a[dab % x]) {
			a[dab % x]--;
			dab++;
		}

		cout << dab << endl;
	}
}