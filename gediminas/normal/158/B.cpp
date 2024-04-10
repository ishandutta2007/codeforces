/*input

8
2 3 4 4 2 1 3 1
*/
#include <bits/stdc++.h>

using namespace std;

int dal(int a, int b) {
	return a / b + (a % b > 0);
}

int main () {
	int n;
	cin >> n;
	int mas[5] = {};

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		mas[a] ++;
	}

	int ats = mas[4];

	if (mas[3] <= mas[1]) {
		ats += mas[3];
		mas[1] -= mas[3];
	}
	else {
		ats += mas[3];
		mas[1] = 0;
	}

	mas[2] += dal(mas[1], 2);

	ats += dal(mas[2], 2);

	cout << ats;

	return 0;
}