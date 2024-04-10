#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		string S; cin >> S;
		int ans = 0;
		for (char a = '0'; a <= '9'; a++) {
			for (char b = '0'; b <= '9'; b++) {
				char x = a, y = b;
				int cnt = 0;
				for (char c : S) {
					if (c == x) {
						cnt++, swap(x, y);
					}
				}
				if (a == b) ans = max(ans, cnt);
				else ans = max(ans, cnt&~1);
			}
		}
		cout << int(S.size())-ans << '\n';
	}

	return 0;
}