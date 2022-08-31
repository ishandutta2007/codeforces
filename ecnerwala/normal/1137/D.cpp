#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (true) {
		cout << "next" << ' ' << 0 << ' ' << 1 << '\n' << flush;
		int k; cin >> k; for (int z = 0; z < k; z++) { string s; cin >> s; }
		cout << "next" << ' ' << 0 << '\n' << flush;
		cin >> k; for (int z = 0; z < k; z++) { string s; cin >> s; }
		assert(k != 1);
		if (k == 2) {
			break;
		}
	}
	while (true) {
		cout << "next"; for (int z = 0; z < 10; z++) {cout << ' ' << z;} cout << '\n' << flush;
		int k; cin >> k; for (int z = 0; z < k; z++) { string s; cin >> s; }
		if (k == 1) {
			cout << "done" << '\n' << flush;
			exit(0);
		}
	}

	return 0;
}