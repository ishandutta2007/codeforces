/*input

1000000001
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	string a;
	cin >> a;
	int c = 0;

	for (int i = 0; i < 7 and i < a.size(); i++)
		c += a[i] - '0';

	bool ar = c == 7 or c == 0;

	for (int i = 7; i < a.size(); i++) {
		c += a[i] - '0';
		c -= a[i - 7] - '0';
		ar = ar or c == 7 or c == 0;
	}

	cout << (ar ? "YES" : "NO");


	return 0;
}