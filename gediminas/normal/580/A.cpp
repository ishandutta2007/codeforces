/*input

3
2 2 9
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int ats = 1;
	int t = 1;
	int mas[n];

	for (int i = 0; i < n; i++)
		cin >> mas[i];

	for (int i = 1; i < n; i++) {
		if (mas[i] >= mas[i - 1])
			t++;
		else {
			ats = max(ats, t);
			t = 1;
		}
	}

	ats = max(ats, t);
	cout << ats;


	return 0;
}