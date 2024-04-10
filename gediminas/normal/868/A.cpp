/*input
ah
1
ha
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	string a;
	cin >> a;
	bool ar[3] = {};
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string b;
		cin >> b;

		if (a == b)
			ar[2] = true;

		if (a[0] == b[1])
			ar[0] = true;

		if (a[1] == b[0])
			ar[1] = true;
	}

	if (ar[0] and ar[1])
		ar[2] = true;

	cout << (ar[2] ? "YES" : "NO");


	return 0;
}