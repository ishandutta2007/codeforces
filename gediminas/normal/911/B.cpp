/*input
4 7 10

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, a, b;
	cin >> n >> a >> b;
	int ats = 1;

	for (int i = 1; i < n; i++) {
		ats = max(ats, min(a / i, b / (n - i)));
	}

	cout << ats;

	return 0;
}