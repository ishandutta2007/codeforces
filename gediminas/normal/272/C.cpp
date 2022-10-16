/*input
1
1
5
1 2
1 10
1 10
1 10
1 10
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	long long prad[n];

	for (int i = 0; i < n; i++)
		cin >> prad[i];

	int m;
	cin >> m;

	long long last = 0;
	long long lasth = 0;

	for (int i = 0; i < m; i++) {
		long long w, h;
		cin >> w >> h;
		last = max(last + lasth, prad[w - 1]);
		cout << last << endl;
		lasth = h;
	}


	return 0;
}