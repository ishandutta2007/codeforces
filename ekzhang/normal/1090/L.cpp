#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

int solve(int a, int b, int na, int nb, int k) {
	if (k > na + nb)
		return 0;
	int best = min((LL) 1e9, ((LL) a * na + (LL) b * nb) / k);
	if (k <= na)
		return best;
	int lo = 0;
	int hi = best;
	while (lo < hi) {
		int mid = (lo + hi + 1) / 2;
		int a2 = a - mid;
		LL b2 = ((LL) b * nb - (LL) (k - na) * mid);
		if (a2 <= b2 / nb)
			return best;
		if (b2 < 0)
			hi = mid - 1;
		else
			lo = mid;
	}
	return lo;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	int T, N, A, B, K;
	cin >> T >> N >> A >> B >> K;

	int na = (N + 1) / 2;
	int nb = N / 2;
	if (A < B) {
		swap(A, B);
		swap(na, nb);
	}

	int ans = solve(A, B, na, nb, K);
	ans = min(ans, T);
	cout << ans << endl;
	return 0;
}