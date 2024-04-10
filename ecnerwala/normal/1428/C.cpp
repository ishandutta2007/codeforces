#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		string S; cin >> S;
		int l = 0;
		for (char c : S) {
			if (c == 'A') {
				l++;
			} else if (c == 'B') {
				if (l) {
					l--;
				} else {
					l++;
				}
			} else assert(false);
		}
		cout << l << '\n';
	}

	return 0;
}