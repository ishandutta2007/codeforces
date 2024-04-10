/*input
0ay1

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string a;
	int ats = 0;
	cin >> a;
	string v = "aeiou";
	string s = "02468";

	for (auto && x : a) {
		if (isalpha(x)) {
			if (v.find(x) != string::npos)
				ats++;
		}
		else {
			if (s.find(x) == string::npos)
				ats++;
		}
	}

	cout << ats;

	return 0;
}