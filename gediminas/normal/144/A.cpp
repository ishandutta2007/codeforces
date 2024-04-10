/*input
7
10 10 58 31 63 40 76
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int mas[n];

	for (int i = 0; i < n; i++)
		cin >> mas[i];

	int pos = 0;

	for (int i = 0; i < n; i++) {
		if (mas[i] > mas[pos])
			pos = i;
	}

	int pos2 = n-1;

	for (int i = n - 1; i >= 0; i--) {
		if (mas[i] < mas[pos2])
			pos2 = i;
	}

	if (pos < pos2)
		cout << pos + n - pos2 - 1;
	else
		cout << pos + n - pos2 - 2;


	return 0;
}