#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << "BW"[i==0 && j == 0];
			}
			cout << '\n';
		}
	}

	return 0;
}