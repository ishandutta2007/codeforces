#include<bits/stdc++.h>
using namespace std;

const int MAXN = 110;
const int MAXR = 6.1e4;

int N;
int R;
vector<pair<int, int>> incr;
vector<pair<int, int>> decr;

int dp[MAXR];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> R;
	for (int i = 0; i < N; i++) {
		int A, B; cin >> A >> B;
		A = max(A, -B);
		if (B >= 0) {
			incr.emplace_back(A, B);
		} else {
			decr.emplace_back(A+B, -B);
		}
	}
	sort(incr.begin(), incr.end());
	sort(decr.begin(), decr.end());
	reverse(decr.begin(), decr.end());

	int incNum = 0;
	for (auto it : incr) {
		if (R < it.first) {
			break;
		}
		R += it.second;
		incNum++;
	}

	dp[R] = incNum;
	for (auto it : decr) {
		for (int i = it.first + it.second; i <= R; i++) {
			dp[i - it.second] = max(dp[i - it.second], dp[i] + 1);
		}
	}
	int ans = 0;
	for (int i = 0; i <= R; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans << '\n';
	return 0;
}