/*input

4 6
10 12 10 7 5 22

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, m;
	cin >> n >> m;
	long long f[m];

	for (int i = 0; i < m; i++)
		cin >> f[i];

	sort(f, f + m);

	long long mi = f[n - 1] - f[0];

	for (int i = 0; i + n - 1 < m; i++)
		mi = min(mi, f[i + n - 1] - f[i]);

	cout << mi;


	return 0;
}