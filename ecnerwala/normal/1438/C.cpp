#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int a; cin >> a;
				if ((a ^ i ^ j) & 1) {
					a++;
				}
				cout << a << " \n"[j+1==M];
			}
		}
	}

	return 0;
}