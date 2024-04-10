#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

int Q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> Q;
	while (Q--) {
		LL a, b, c;
		cin >> a >> b >> c;

		cout << (a + b + c) / 2 << '\n';
	}

	cout.flush();
	return 0;
}