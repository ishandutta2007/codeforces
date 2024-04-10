#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 103
int N;
LL K;
string S;
LL dp[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K >> S;

	for (int i = N; i >= 0; i--) {
		dp[i][0] = 1;
		set<char> s;
		for (int j = i; j < N; j++) {
			if (!s.count(S[j])) {
				s.insert(S[j]);
				for (int k = 0; k < N; k++)
					dp[i][k + 1] += dp[j + 1][k];
			}
		}
	}
	
	LL cost = 0;
	for (int i = 0; i <= N; i++) {
		LL cnt = min(dp[0][N - i], K);
		cost += cnt * i;
		K -= cnt;
		if (!K)
			break;
	}

	cout << (K ? -1 : cost) << endl;
	return 0;
}