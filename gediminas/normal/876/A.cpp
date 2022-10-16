/*input
1
2
3
5
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	n--;
	cout << min({n * a, n * b, a + max((n - 1) * c, 0), max(b + (n - 1) * c, 0)});


	return 0;
}