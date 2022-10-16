/*input
5 2 1 5
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, p, l, r;
	cin >> n >> p >> l >> r;

	if (l == 1 and r == n)
		cout << 0;
	else if (l == 1)
		cout << abs(p - r) + 1;
	else if (r == n)
		cout << abs(p - l) + 1;
	else
		cout << min(abs(p - l), abs(p - r)) + r - l + 2;


	return 0;
}