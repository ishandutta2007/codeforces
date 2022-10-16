/*input
5
! abc
. ad
. b
! cd
? c
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	bool negal[26] = {};
	int ats = 0;
	char r = 0;

	for (int i = 0; i < n; i++) {
		char x;
		string a;
		cin >> x >> a;

		if (r != 0) {
			if (x == '!')
				ats++;
			else if (x == '?' and r != a[0])
				ats++;
		}

		if (x == '?' || x == '.') {
			for (auto && y : a)
				negal[y - 'a'] = true;
		}
		else if (x == '!') {
			bool neg[26] = {};

			for (auto && y : a)
				neg[y - 'a'] = true;

			for (int i = 0; i < 26; i++) {
				if (!neg[i])
					negal[i] = true;
			}
		}

		r = 0;

		for (int i = 0; i < 26; i++) {
			if (r == 0 and !negal[i])
				r = i + 'a';
			else if (!negal[i])
				r = 1;

			//cout << negal[i];
		}

		if (r == 1)
			r = 0;

		//cout << " " << ats << endl;
	}

	cout << ats;


	return 0;
}