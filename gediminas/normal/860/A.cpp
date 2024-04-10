/*input
hghghghghg

*/
#include <bits/stdc++.h>

using namespace std;

bool balse(char a) {
	return a == 'a' or a == 'e' or a == 'i' or a == 'o' or a == 'u';
}

bool diff(char a, char b, char c) {
	return !(a == b and b == c);
}

int main () {
	string a;
	cin >> a;

	bool isv = false;

	for (int i = 0; i < a.size(); i++) {
		if (isv) {
			if (i + 2 < a.size() and !balse(a[i]) and !balse(a[i + 1]) and !balse(a[i + 2]) and diff(a[i], a[i + 1], a[i + 2])) {
				cout << a[i + 1] << " " << a[i + 2];
				i++;
				isv = true;
			}
			else
				isv = false;
		}
		else {
			if (i + 2 < a.size() and !balse(a[i]) and !balse(a[i + 1]) and !balse(a[i + 2]) and diff(a[i], a[i + 1], a[i + 2])) {
				cout << a[i] << a[i + 1] << " " << a[i + 2];
				i++;
				isv = true;
			}
			else {
				cout << a[i];
				isv = false;
			}
		}
	}


	return 0;
}