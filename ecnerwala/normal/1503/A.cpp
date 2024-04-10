#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		string S; cin >> S;
		int c0 = 0;
		int c1 = 0;
		for (char c : S) {
			if (c == '0') c0++;
			else if (c == '1') c1++;
			else assert(false);
		}
		string A; A.reserve(N);
		string B; B.reserve(N);
		int sa = 0, sb = 0;

		if (c1 & 1) goto bad;
		c1 /= 2;
		for (char c : S) {
			if (c == '0') {
				if (c0 % 2 == 0) {
					A += '(';
					B += ')';
					sa ++;
					sb --;
				} else {
					A += ')';
					B += '(';
					sa --;
					sb ++;
				}
				c0--;
			} else if (c == '1') {
				if (c1 > 0) {
					A += '(';
					B += '(';
					sa++;
					sb++;
				} else {
					A += ')';
					B += ')';
					sa--;
					sb--;
				}
				c1--;
			} else assert(false);
			if (sa < 0 || sb < 0) {
				goto bad;
			}
		}
		cout << "YES" << '\n';
		cout << A << '\n';
		cout << B << '\n';
		continue;
bad:
		cout << "NO" << '\n';
	}

	return 0;
}