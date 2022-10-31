#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T-- > 0) {
		int n, k;
		cin >> n >> k;
		int l = 2 * k - n;
		int i;
		for (i = 1; i < l; i++) cout << i << ' ';
		for (i = k; i >= l; i--) cout << i << ' ';
		cout << endl;
	}
}