/*input
7 6

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	long long n, k;
	cin >> n >> k;
	long long odd = n / 2 + n % 2;

	if (k <= odd)
		cout << 2 * k - 1;
	else
		cout << 2 * (k - odd);

	return 0;
}