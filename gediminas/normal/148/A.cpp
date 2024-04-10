/*input
2
3
4
5
24

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int x = 0;
	int a, b, c, d, n;
	cin >> a >> b >> c >> d >> n;

	for (int i = 1; i <= n; i++)
		x += i % a == 0 or i % b == 0 or i % c == 0 or i % d == 0;

	cout << x;

	return 0;
}