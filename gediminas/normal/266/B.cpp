/*input
4 1
GGGB

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, t;
	cin >> n >> t;
	string a;
	cin >> a;
	string b;

	for (int i = 0; i < t; i++) {
		b = a;

		for (int j = 1; j < n; j++) {
			if (a[j - 1] == 'B' and a[j] == 'G')
				swap(b[j - 1], b[j]);
		}

		a = b;
	}

	cout << b;



	return 0;
}