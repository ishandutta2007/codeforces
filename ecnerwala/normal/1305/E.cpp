#include<bits/stdc++.h>
using namespace std;

int maxScore(int N) {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += i/2;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M; cin >> N >> M;
	if (maxScore(N) < M) {
		cout << -1 << '\n';
		return 0;
	}

	int oldN = N;
	while (N > 1 && maxScore(N-1) >= M) N--;

	for (int i = 1; i < N; i++) {
		cout << i << ' ';
	}
	int lastValue = M - maxScore(N-1);
	cout << 2*(N - lastValue) - 1 << ' ';

	for (int i = N+1; i <= oldN; i++) {
		cout << i*i*2+1 << ' ';
	}

	cout << '\n';
	return 0;
}