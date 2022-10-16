/*input
5 4
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	long long n, k;
	cin >> n >> k;

	if (k == 0 or k == 1)
		cout << 1;
	else if (k == 2)
		cout << 1 + n*(n - 1) / 2;
	else if (k == 3)
		cout << 1 + n*(n - 1) / 2 + n*(n - 1)*(n - 2) / 3;
	else if (k == 4)
		cout << 1 + n*(n - 1) / 2 + n*(n - 1)*(n - 2) / 3 + n*(n - 1)*(n - 2)*(n - 3) * 9 / 24;

	/*string a = "1234";

	do {
		cout << a << endl;
	}
	while (next_permutation(a.begin(), a.end()));*/

	return 0;
}