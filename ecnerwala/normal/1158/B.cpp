#include<bits/stdc++.h>
using namespace std;

string go(int N, int K) {
	assert(N % 2 == K % 2);
	int p = (N-K + 2) / 2;
	if (K == 1) p = N;
	string s;
	for (int i = 0; i < N; i++) {
		if (i % p == 0) {
			s += '0';
		} else {
			s += '1';
		}
	}
	return s;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, K; cin >> N >> K;
	string ans = go(N, K);
	cout << ans << '\n';

	return 0;
}