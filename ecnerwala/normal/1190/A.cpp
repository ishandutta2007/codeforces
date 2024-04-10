#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll N, M, K; cin >> N >> M >> K;
	vector<ll> P(M);
	for (int i = 0; i < M; i++) cin >> P[i];

	int ans = 0;
	int ind = 0;
	while (ind < M) {
		ans++;
		ll numSub = ind + 1;
		numSub += (P[ind] - numSub) / K * K;
		while (ind < M && P[ind] - numSub < K) {
			ind++;
		}
	}
	cout << ans << '\n';

	return 0;
}