/*input
5
1 2
2 1
5 10
10 9
19 1
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	vector<int> x(n + 1), h(n + 1);

	for (int i = 0; i < n; i++)
		cin >> x[i] >> h[i];

	x[n] = INT_MAX;
	h[n] = 0;

	int k = 0;
	int iki = INT_MIN;

	for (int i = 0; i < n; i++) {
		if (iki < x[i] - h[i]) {
			iki = x[i];
			k++;
		}
		else if (iki < x[i] and x[i] + h[i] < x[i + 1]) {
			iki = x[i] + h[i];
			k++;
		}
		else
			iki = max(iki, x[i]);
	}

	cout << k << endl;

	return 0;
}