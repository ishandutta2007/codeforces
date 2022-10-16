/*input
4

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int i = 0;

	for (; i * i < n; i++);

	int j = 0;

	for (; j * (j - 1) < n; j++);

	cout << min(4 * i, 4 * j - 2);

	return 0;
}