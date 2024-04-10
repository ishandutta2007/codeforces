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

const int K = 5555;
long long dp[K][K];

int main(){

	int n = nxt(), k = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		a[i] = nxt();
	sort(all(a));
	dp[0][0] = 0;
	// for (int i = 0; i < K; i++){
	// 	for (int j = 0; j < K; j++)
	// 		dp[i][j] = LLONG_MAX;
	// }
	int m = n / k;
	for (int i = 1; i <= k; i++){
		int pos = m * i - 1;
		dp[i][0] = a[pos] - a[pos - m + 1] + dp[i - 1][0];
		for (int j = 1; j < i; j++){
			++pos;
			if (pos >= n)
				break;
			dp[i][j] = min(dp[i - 1][j] + a[pos] - a[pos - m + 1], dp[i - 1][j - 1] + a[pos] - a[pos - m]);
		}
		++pos;
		if (pos >= n)
			continue;
		dp[i][i] = a[pos] - a[pos - m] + dp[i - 1][i - 1];
	}
	cout << dp[k][n % k] << "\n";

	return 0;
}