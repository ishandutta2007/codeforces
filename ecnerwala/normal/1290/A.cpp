#include<bits/stdc++.h>
using namespace std;

const int INF = int(1e9) + 200;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int N, M, K; cin >> N >> M >> K;
		vector<int> A(N);
		for (int i = 0; i < N; i++) cin >> A[i];
		vector<int> V(M);
		for (int i = 0; i < M; i++) {
			V[i] = max(A[i], A[N-M+i]);
		}
		K = min(K, M-1);
		int ans = -INF;
		for (int a = 0; a <= K; a++) {
			int curVal = INF;
			for (int b = 0; b <= M-1-K; b++) {
				curVal = min(curVal, V[a+b]);
			}
			ans = max(ans, curVal);
		}
		cout << ans << '\n';
	}

	return 0;
}