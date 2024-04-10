/*input
5
0 1 0 1 3

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int last[n + 1] = {};
	int tvark[n + 1] = {};
	int koks[n + 1] = {};
	int ats = 1;

	for (int i = 1; i <= n; i++) {
		cin >> tvark[i];
		koks[i] = koks[tvark[i]];

		if (last[koks[tvark[i]]] != tvark[i])
			koks[i] = ats++;

		last[koks[i]] = i;
	}

	cout << ats;

	return 0;
}