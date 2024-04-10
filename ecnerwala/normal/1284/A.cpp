#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M; cin >> N >> M;
	vector<string> S(N);
	vector<string> T(M);
	for (int i = 0; i < N; i++) cin >> S[i];
	for (int j = 0; j < M; j++) cin >> T[j];
	int Q; cin >> Q;
	while (Q--) {
		long long y; cin >> y;
		y--;
		cout << S[y % N] << T[y % M] << '\n';
	}

	return 0;
}