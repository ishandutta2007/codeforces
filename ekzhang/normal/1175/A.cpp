#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

int T;
LL N, K;

LL solve() {
	LL ans = 0;
	while (N >= K) {
		ans += N % K + 1;
		N /= K;
	}
	return ans + N;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> T;
	while (T--) {
		cin >> N >> K;
		cout << solve() << '\n';
	}

	cout.flush();
	return 0;
}