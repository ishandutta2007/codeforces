#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
	int n;
	cin >> n;
	vector <vector <pair <int, int>>> dp(n, vector <pair <int, int>>(n, { INF, INF }));
	for (int i = 0; i < n; i++) {
		cin >> dp[i][i].second;
		dp[i][i].first = 1;
	}
	for (int len = 1; len < n; len++) {
		for (int L = 0; L < n - len; L++)
			for (int R = L; R < L + len; R++) {
				pair <int, int> v1 = dp[L][R], v2 = dp[R + 1][L + len];
				if (v1.first == 1 && v2.first == 1 && v1.second == v2.second)
					dp[L][L + len] = { 1, v2.second + 1 };
				else
					dp[L][L + len].first = min(dp[L][L + len].first, v1.first + v2.first);
			}
	}
	cout << dp[0][n - 1].first;
	return 0;
}