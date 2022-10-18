/*input

3
3 -1 7
-5 2 -4
2 -1 -3

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int x = 0, y = 0, z = 0, n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		x += a;
		y += b;
		z += c;
	}

	cout << (x == 0 and y == 0 and z == 0 ? "YES" : "NO");


	return 0;
}