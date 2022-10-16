/*input
8
1
1
1
1
3
3
3
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int kiek[n] = {};

	int mas[n] = {};
	bool lap[n] = {};

	for (int i = 1; i < n; i++) {
		cin >> mas[i];
		lap[mas[i] - 1] = true;
	}

	for (int i = 1; i < n; i++) {
		if (!lap[i])
			kiek[mas[i] - 1]++;
	}

	bool ar = true;

	for (int i = 0; i < n; i++)
		ar &= (kiek[i] >= 3 || !lap[i]);

	cout << (ar ? "Yes" : "No");

	return 0;
}