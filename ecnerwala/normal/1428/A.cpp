#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int64_t X1, Y1, X2, Y2; cin >> X1 >> Y1 >> X2 >> Y2;
		int64_t dx = abs(X2 - X1);
		int64_t dy = abs(Y2 - Y1);
		if (dx && dy) {
			cout << dx + dy + 2 << '\n';
		} else {
			cout << dx + dy << '\n';
		}

	}

	return 0;
}