#include<bits/stdc++.h>
using namespace std;

long long cnt[int(2e3)];

int main() {
	ios_base::sync_with_stdio(0);
	int N, M; cin >> N >> M;
	for (int i = 0; i < M; i++) cnt[i] += N / M;
	N %= M;
	for (int i = 1; i <= N; i++) {
		cnt[i%M]++;
	}
	long long res = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			if ((i * i + j * j) % M == 0) {
				res += cnt[i] * cnt[j];
			}
		}
	}
	cout << res << '\n';

	return 0;
}