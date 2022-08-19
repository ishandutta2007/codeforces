#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int N; ll M, K; cin >> N >> M >> K;
		vector<ll> H(N);
		for (int i = 0; i < N; i++) cin >> H[i];
		bool isGood = true;
		for (int i = 0; i+1 < N; i++) {
			ll tgt = max(H[i+1] - K, 0ll);
			H[i] += M;
			if (H[i] < tgt) {
				isGood = false;
				break;
			}
			M = H[i] - tgt;
		}
		cout << (isGood ? "YES" : "NO") << '\n';
	}

	return 0;
}