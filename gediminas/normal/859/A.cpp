/*input

25
2 3 4 5 6 7 8 9 10 11 12 14 15 16 17 18 19 20 21 22 23 24 25 26 28
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int k;
	cin >> k;
	int a;
	int mi = 0;

	for (int i = 0; i < k; i++) {
		cin >> a;
		mi = max(mi, a);
	}

	cout << max(mi - 25, 0);


	return 0;
}