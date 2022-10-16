/*input

3
1 2 3
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int mas[n];

	for (int i = 0; i < n; i++)
		cin >> mas[i];

	int c = 0;

	for (int i = 1; i < n - 1; i++) {
		if ((mas[i - 1]<mas[i] and mas[i]>mas[i + 1]) or (mas[i - 1] > mas[i] and mas[i] < mas[i + 1]))
			c++;
	}

	cout << c;

	return 0;
}