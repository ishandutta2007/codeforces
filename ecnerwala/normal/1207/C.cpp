#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2.1e5;
char S[MAXN];
int H[MAXN];

using ll = long long;
const ll INF = 1e18;

ll go() {
	int N; cin >> N;
	ll A, B; cin >> A >> B;

	for (int i = 0; i <= N; i++) {
		H[i] = 0;
	}
	cin >> S;
	for (int i = 0; i < N; i++) {
		if (S[i] == '1') {
			H[i] = 1;
			H[i+1] = 1;
		}
	}

	ll dp[2] = {0, INF};
	for (int i = 1; i <= N; i++) {
		ll ndp[2] = {INF, INF};
		for (int p = 0; p < 2; p++) {
			for (int n = H[i]; n < 2; n++) {
				ndp[n] = min(ndp[n], dp[p] + abs(p - n) * A);
			}
		}
		dp[0] = ndp[0];
		dp[1] = ndp[1] + B;
	}
	return dp[0] + A * N + B * (N+1);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		cout << go() << '\n';
	}

	return 0;
}