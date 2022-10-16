#include <bits/stdc++.h>

using namespace std;
/*input
2
*/
/*input
3
*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	string a = "aa";

	if (n == 1) {
		a = "a";
	}

	for (int i = 2; i < n; ++i) {
		if (a[i - 2] == 'a') {
			a.push_back('b');
		}
		else {
			a.push_back('a');
		}
	}

	cout << a;
}