#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N, X; cin >> N >> X;
		if (N <= 2) {
			cout << 1 << '\n';
		} else {
			cout << 2 + (N - 3) / X << '\n';
		}
	}

	return 0;
}