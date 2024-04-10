/*input
3
1 10
0 10
10 10

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int a = 0;

	for (int i = 0; i < n; i++) {
		int p, q;
		cin >> p >> q;
		a += (q - p >= 2);
	}

	cout << a;


	return 0;
}