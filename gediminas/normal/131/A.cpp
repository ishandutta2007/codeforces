/*input

cAPS
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	string a;
	cin >> a;
	int c = 0;

	for (int i = 1; i < a.size(); i++)
		c += isupper(a[i]) > 0;

	if (c == a.size() - 1) {
		for (int i = 0; i < a.size(); i++) {
			if (isupper(a[i]))
				a[i] = tolower(a[i]);
			else
				a[i] = toupper(a[i]);
		}
	}

	cout << a;

	return 0;
}