/*input
3
1 1 0
1 1 1
1 0 0

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int cc = 0;

	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a + b + c >= 2)
			cc++;
	}

	cout << cc;


	return 0;
}