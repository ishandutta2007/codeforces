/*input
3 17 4

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	long long k, n, w;
	cin >> k >> n >> w;
	cout << max(0ll, (w + 1)*w / 2 * k - n);


	return 0;
}