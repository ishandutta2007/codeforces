#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		bool has_symmetric = false;
		while (N--) {
			int a, b, c, d; cin >> a >> b >> c >> d;
			if (b == c) has_symmetric = true;
		}
		if (M % 2 == 0 && has_symmetric) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}