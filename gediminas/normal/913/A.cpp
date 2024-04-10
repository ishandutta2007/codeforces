/*input
1
58

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	long long n, m;
	cin >> n >> m;

	if (n > 30)
		cout << m << endl;
	else
		cout << m % (1ll << n) << endl;

	return 0;
}