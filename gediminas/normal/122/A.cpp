/*input
78

*/
#include <bits/stdc++.h>

using namespace std;

vector<int> luc;

void gen(int nr) {
	nr *= 10;

	if (nr + 4 <= 1000) {
		luc.push_back(nr + 4);
		gen(nr + 4);
	}

	if (nr + 7 <= 1000) {
		luc.push_back(nr + 7);
		gen(nr + 7);
	}
}

int main () {
	gen(0);
	int a;
	cin >> a;

	for (int i = 0; i < luc.size(); i++) {
		if (a % luc[i] == 0) {
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";


	return 0;
}