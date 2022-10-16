/*input

10
1100111010
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	bool ar = false;
	int k = 0;
	string sk = "";

	for (int i = 0; i < n; i++) {
		char x;
		cin >> x;

		if (x == '1') {
			ar = true;
			k++;
		}
		else {
			ar = false;
			sk.push_back('0' + k);
			k = 0;
		}
	}

	sk.push_back('0' + k);

	cout << sk;


	return 0;
}