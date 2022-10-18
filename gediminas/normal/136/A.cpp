/*input
2
1 2
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int ats[n];

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		ats[x - 1] = i + 1;
	}

	for (int i = 0; i < n; i++)
		cout << ats[i] << " ";


	return 0;
}