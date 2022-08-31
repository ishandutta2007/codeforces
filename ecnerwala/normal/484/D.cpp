#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e6;
int N;
ll A[MAXN];
ll dp[MAXN][2];
ll dir[MAXN];

ll sign(ll a) { return a ? (a > 0 ? 1 : -1) : 0; }

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	for(int i = 0; i < N; i++) cin >> A[i];
	memset(dp, 0, sizeof(dp));
	dir[0] = 0;
	for(int i = 1; i < N; i++) {
		dir[i] = sign(A[i] - A[i - 1]);
		ll dist = abs(A[i] - A[i - 1]);
		if(dir[i] != 0 && dir[i] == dir[i - 1]) {
			dp[i][1] = dp[i - 1][1] + dist;
			dp[i][0] = dp[i - 1][1];
		} else {
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + dist);
			dp[i][0] = dp[i - 1][1];
		}
		assert(dp[i][1] >= dp[i][0]);
	}
	cout << max(dp[N - 1][0], dp[N - 1][1]) << '\n';
	return 0;
}