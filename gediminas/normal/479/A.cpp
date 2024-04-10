/*input

2
10
3
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int a, b, c;
	cin >> a >> b >> c;
	cout << max({a + b + c, a *b * c, a + b * c, a * b + c, (a + b)*c, a * (b + c)});


	return 0;
}