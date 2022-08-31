#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		int tot = 0;
		while (N--) {
			int a; cin >> a; a--; tot ^= (a & 1);
		}
		cout << (tot ? "errorgorn" : "maomao90") << '\n';
	}

	return 0;
}