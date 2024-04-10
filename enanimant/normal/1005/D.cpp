#include <bits/stdc++.h>

using namespace std;


const int MAXL = (int) 2e5;

string s;
int n;
int psa[MAXL + 1];
int dp[MAXL + 1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG)


	cin >> s;
	n = s.length();
	psa[0] = 0;
	for (int i = 0; i < n; i++) {
		psa[i + 1] = psa[i] + s[i] - '0';
	}

	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];
		for (int j = 1; j <= 3; j++) {
			if (i - j >= 0 && (psa[i] - psa[i - j]) % 3 == 0) {
				dp[i] = max(dp[i], dp[i - j] + 1);
			}
		}
	}

	cout << dp[n] << '\n';

	return 0;
}