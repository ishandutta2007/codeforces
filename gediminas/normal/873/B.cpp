/*input
2
01

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	string a;
	cin >> a;
	map<int, int> b;
	int nul = 0;
	int ats = 0;
	b[0] = -1;

	for (int i = 0; i < n; i++) {
		if (a[i] == '0')
			nul++;

		if (b.count(i - 2 * nul + 1) == 0)
			b[i - 2 * nul + 1] = i;
		else
			ats = max(ats, i - b[i - 2 * nul + 1]);
	}

	cout << ats;


	return 0;
}