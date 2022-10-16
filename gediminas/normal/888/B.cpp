/*input
5
RRRUU

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int a = 0, b = 0;

	for (int i = 0; i < n; i++) {
		char x;
		cin >> x;

		if (x == 'U')
			a++;
		else if (x == 'D')
			a--;

		if (x == 'L')
			b++;
		else if (x == 'R')
			b--;
	}

	cout << n - abs(a) - abs(b);

	return 0;
}