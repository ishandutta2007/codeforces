#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

int T, N;
string S;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> T;
	while (T--) {
		cin >> N >> S;
		for (char c : S) {
			if (c == 'U') {
				cout << 'D';
			} else if (c == 'D') {
				cout << 'U';
			} else {
				cout << c;
			}
		}
		cout << '\n';
	}

	cout.flush();
	return 0;
}