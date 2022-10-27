#include <bits/stdc++.h>
using namespace std;

const int maxn = 255;
const int inf = 1e9;

int a[maxn], b[maxn], dp[maxn][maxn][maxn];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int m; cin >> m;
	
	b[0] = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		b[i] = b[i - 1] + a[i];
	}
	for(int i = 0; i <= n; i++){
		for(int sm = 0; sm <= m; sm++){
			for(int pr = 0; pr <= m; pr++){
				dp[i][sm][pr] = inf;
			}
		}
	}

	dp[0][0][m] = 0;
	for(int i = 1; i <= n; i++){
		for(int sm = 0; sm <= m; sm++){
			int minima = inf;
			for(int nw = m; nw >= 0; nw--){
				minima = min(minima, dp[i - 1][sm][nw]);
				if(sm + nw <= m)dp[i][sm + nw][nw] = min(dp[i][sm + nw][nw], minima + abs(sm + nw - b[i]));
			}
		}
	}
	int ans = inf;
	for(int i = 0; i <= m; i++){
		ans = min(ans, dp[n][m][i]);
	}
	cout << ans << '\n';

	return 0;
}