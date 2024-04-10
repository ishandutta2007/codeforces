#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		bool good = true;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int a; cin >> a;
				int v = (i-1 >= 0) + (i+1 < N) + (j-1 >= 0) + (j+1 < M);
				if (a > v) {
					good = false;
				}
			}
		}
		if (good) {
			cout << "YES" << '\n';
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					int v = (i-1 >= 0) + (i+1 < N) + (j-1 >= 0) + (j+1 < M);
					cout << v << " \n"[j+1==M];
				}
			}
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}