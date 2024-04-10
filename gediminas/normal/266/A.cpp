/*input
4
BRBG
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int ats = 0, te = 1;
	string a;
	cin >> a;

	for (int i = 1; i < n; i++) {
		if (a[i] == a[i - 1])
			te++;
		else {
			ats += te - 1;
			te = 1;
		}
	}

	ats += te - 1;

	cout << ats;


	return 0;
}