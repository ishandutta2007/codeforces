#include <bits/stdc++.h>

using namespace std;
/*input
8
*/
/*input
10

*/
/*input
14
*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	long long n;
	cin >> n;
	long long s = n;

	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			s += n / i;
			n = n / i;
			i = 1;
		}
	}

	cout << s + 1;
}