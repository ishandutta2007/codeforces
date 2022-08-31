#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){

	int n = nxt();
	vector<vector<int>> dp(n + 1, vector<int>(3, 0));
	for (int i = 0; i < n; i++){
		int x = nxt();
		for (int j = 0; j < 4; j++){
			dp[i + 1][j] = -1;
		}
		dp[i + 1][0] = max(dp[i][0], max(dp[i][1], dp[i][2]));
		if (x & 1){
			dp[i + 1][1] = max(dp[i][0] + 1, dp[i][2] + 1);
		}
		if (x & 2){
			dp[i + 1][2] = max(dp[i][0] + 1, dp[i][1] + 1);
		}
	}

	cout << n - max(dp[n][0], max(dp[n][1], dp[n][2])) << "\n";

	return 0;
}