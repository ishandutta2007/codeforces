#include<bits/stdc++.h>
using namespace std;

const int MAXN = 17;
const int MAXK = 2008;
const int MAXS = 2008;
using bs = bitset<MAXS>;
int N, K;
int A[MAXN];
bs dp2[1 << 16]; // can get to this state
bs dp[1 << 16]; // can get to this state

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	dp[0][0] = true;
	for (int m = 1; m < (1 << N); m++) {
		for (int i = 0; i < N; i++) {
			if (!(m & (1 << i))) continue;
			dp2[m] |= dp[m ^ (1 << i)] << A[i];
		}
		dp[m] = dp2[m];
		for (int v = (MAXS-1) / K, u = v * K; v > 0; v --, u -= K) {
			if (dp[m][u]) dp[m][v] = true;
		}
	}

	if (!dp[(1 << N) - 1][1]) {
		cout << "NO" << '\n';
		exit(0);
	}
	cout << "YES" << '\n';
	priority_queue<pair<int, int>> shift;
	for (int m = (1 << N) - 1, s = 1, l = 0; m > 0; ) {
		assert(dp[m][s]);
		while (!dp2[m][s]) s *= K, l++;
		assert(dp2[m][s]);
		int i;
		for (i = 0; i < N; i++) {
			if (!(m & (1 << i))) continue;
			if (s >= A[i] && dp[m^(1 << i)][s - A[i]]) {
				break;
			}
		}
		assert(i != N);
		shift.emplace(l, A[i]);
		s -= A[i];
		m ^= (1 << i);
	}
	while (shift.size() > 1) {
		auto v1 = shift.top(); shift.pop();
		auto v2 = shift.top(); shift.pop();
		assert(v1.first == v2.first);
		int l = v1.first;
		cout << v1.second << ' ' << v2.second << '\n';
		int s = v1.second + v2.second;
		while (s % K == 0) {
			l--;
			s /= K;
		}
		shift.emplace(l, s);
	}
	assert(shift.top().first == 0 && shift.top().second == 1);

	return 0;
}