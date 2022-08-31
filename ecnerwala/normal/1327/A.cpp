#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int64_t N, K; cin >> N >> K;
		cout << (N % 2 == K % 2 && N >= K * K ? "YES" : "NO") << '\n';
	}
	return 0;
}