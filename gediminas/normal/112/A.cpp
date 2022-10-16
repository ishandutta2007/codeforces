/*input
abs
Abz

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	string a, b;
	cin >> a >> b;

	for (auto && i : a)
		i = tolower(i);

	for (auto && i : b)
		i = tolower(i);

	if (a == b)
		cout << 0;
	else if (a < b)
		cout << -1;
	else
		cout << 1;

	return 0;
}