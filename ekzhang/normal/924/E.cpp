#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 10013
int N, L, R, S;
pair<int, int> A[MAXN];
int dp[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
		cin >> A[i].first, S += A[i].first;
	for (int i = 0; i < N; i++)
		cin >> A[i].second;

	L = S - L, R = S - R;

	sort(A, A + N, [](auto p, auto q) {
		return p.second == q.second ? p.first > q.first : p.second < q.second;
	});

	for (int i = 1; i <= S; i++)
		dp[i] = -N;

	for (int i = 0; i < N; i++) {
		int k = A[i].first, b = A[i].second;
		for (int j = S - k; j >= 0; j--)
			dp[j + k] = max(dp[j + k], dp[j] + (b && j + k >= R && j + k <= L));
	}

	int ans = 0;
	for (int i = 0; i <= S; i++)
		ans = max(ans, dp[i]);

	cout << ans << endl;
	return 0;
}