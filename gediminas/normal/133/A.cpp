/*input
Codeforces


*/
#include <bits/stdc++.h>

using namespace std;

int main () {

	string a;
	getline(cin, a);

	bool ar = false;

	for (auto && i : a) {
		if (i == 'H' or i == 'Q' or i == '9')
			ar = true;
	}

	cout << (ar ? "YES" : "NO");

	return 0;
}