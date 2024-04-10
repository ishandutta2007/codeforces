/*input
15 1 100 0 0
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int c, v0, v1, a, l;
	cin >> c >> v0 >> v1 >> a >> l;
	int ats = 0;
	int dab = 0;

	while (true) {
		dab += min(v0 + ats * a, v1);
		ats++;

		if (dab >= c)
			break;

		dab -= l;
	}

	cout << ats;


	return 0;
}