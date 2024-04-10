#include<bits/stdc++.h>
using namespace std;

inline void setmax(int &a, int b) { if(b > a) a = b; }

const int MAXN = 2e5;
int N;
char S[MAXN];
int dp[MAXN][2][8];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	cin >> S;

	for(int i = 0; i < N; i++) {
		bool v = S[i] - '0';
		for(int k = 0; k <= 2; k++) for(int b = 0; b < 2; b++) dp[i + 1][b][k] = dp[i][b][k];
		setmax(dp[i + 1][v][0], dp[i][!v][0] + 1);
		setmax(dp[i + 1][v][1], dp[i][!v][1] + 1);
		setmax(dp[i + 1][v][2], dp[i][!v][2] + 1);
		setmax(dp[i + 1][v][1], dp[i + 1][!v][0]);
		setmax(dp[i + 1][!v][1], dp[i + 1][v][0]);
		setmax(dp[i + 1][v][2], dp[i + 1][!v][1]);
		setmax(dp[i + 1][!v][2], dp[i + 1][v][1]);
	}

	cout << max(dp[N][0][2], dp[N][1][2]) << '\n';


	return 0;
}