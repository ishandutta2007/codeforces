/*input
2013

*/
#include <bits/stdc++.h>

using namespace std;

bool check(int m) {
	bool mas[10] = {};

	while (m > 0) {
		if (mas[m % 10])
			return false;

		mas[m % 10] = true;
		m /= 10;
	}

	return true;
}

int main () {
	int m;
	cin >> m;

	while (!check(++m));

	cout << m;


	return 0;
}