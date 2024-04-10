#include <bits/stdc++.h>

using namespace std;
/*input
6
7
1
2
3
2000000000
763243547

*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		cout << max(0ll, (n + 1) / 2 - 1) << "\n";
	}

}