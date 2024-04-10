#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		string S; cin >> S;
		int ans = 0;
		int c0 = 0, c1 = 0;
		for (char c : S) {
			if (c == '(') c0++;
			else if (c == ')') { if(c0) ans++, c0--; }
			else if (c == '[') c1++;
			else if (c == ']') { if (c1) ans++, c1--; }
			else assert(false);
		}
		cout << ans << '\n';
	}

	return 0;
}