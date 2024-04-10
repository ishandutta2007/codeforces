#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int A, B; cin >> A >> B;
		int ans = 0;
		int cnt0 = A+1;
		string s; cin >> s;
		for (char c : s) {
			if (c == '0') {
				cnt0++;
			} else {
				ans += min(A, B * cnt0);
				cnt0 = 0;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}