#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 100013
int N, U;
int A[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> U;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	double ans = -1;
	int idx = 0;
	for (int i = 0; i + 1 < N; i++) {
		while (idx + 1 < N && A[idx + 1] - A[i] <= U) ++idx;
		if (idx - i >= 2) {
			ans = max(ans, 1.0 * (A[idx] - A[i + 1]) / (A[idx] - A[i]));
		}
	}

	if (ans < 0)
		cout << -1 << endl;
	else
		cout << fixed << setprecision(10) << ans << endl;
	return 0;
}