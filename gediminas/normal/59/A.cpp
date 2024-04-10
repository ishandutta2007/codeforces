#include <bits/stdc++.h>

using namespace std;

/*input
HoUse
*/
/*input
ViP
*/
/*input
maTRIx
*/
int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string a;
	cin >> a;
	int c = 0;
	int l = 0;

	for (auto && i : a) {
		if (isupper(i))
			c++;
		else
			l++;
	}

	if (c > l) {
		for (auto && i : a) {
			i = toupper(i);
		}
	}
	else {
		for (auto && i : a) {
			i = tolower(i);
		}
	}


	cout << a;
}