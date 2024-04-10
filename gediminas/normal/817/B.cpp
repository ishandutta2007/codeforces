/*input
5
1 3 2 3 4
*/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

int main () {
	int n;
	cin >> n;
	long long mas[n];

	for (int i = 0; i < n; i++)
		cin >> mas[i];

	sort(mas, mas + n);

	if (mas[0] == mas[1] and mas[1] == mas[2]) {
		long long c = 0;

		for (int i = 0; i < n; i++)
			c += mas[i] == mas[0];

		cout << c*(c - 1)*(c - 2) / 6;
	}
	else if (mas[1] == mas[2]) {
		long long c = 0;

		for (int i = 0; i < n; i++)
			c += mas[i] == mas[2];

		cout << c * (c - 1) / 2 << endl;
	}
	else {
		long long c = 0;

		for (int i = 0; i < n; i++)
			c += mas[i] == mas[2];

		cout << c << endl;
	}



	return 0;
}