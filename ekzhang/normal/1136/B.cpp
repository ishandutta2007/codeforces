#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

int N, K;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K;
	int ans = 1 + 2 * N;
	ans += min(N - 1 + K - 1, N - 1 + (N - K));

	cout << ans << endl;
	return 0;
}