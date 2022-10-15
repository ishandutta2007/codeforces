#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define MAXN 20000013
int N;
LL X, Y;
LL dp[MAXN];

void u(LL& x, LL y) {
	x = min(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> X >> Y;
	for (int i = 0; i <= N; i++) {
		dp[i] = X * i;
	}

	for (int i = 0; i < N; i++) {
		u(dp[2 * i], dp[i] + Y);
		u(dp[2 * i + 1], dp[i] + X + Y);
		u(dp[2 * i - 1], dp[i] + X + Y);
	}

	cout << dp[N] << endl;

	return 0;
}