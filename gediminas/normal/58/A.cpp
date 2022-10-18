/*input
hlelo

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	string a;
	cin >> a;
	string b = "hello";
	int poi = 0;

	for (int i = 0; i < a.size(); i++) {
		if (poi < b.size() and a[i] == b[poi])
			poi++;
	}

	cout << (poi == b.size() ? "YES" : "NO");


	return 0;
}