#include <bits/stdc++.h>
using namespace std;

const int maxn = 205;

int parent[maxn], opt[maxn][maxn];
long long cost[maxn][maxn], total[maxn], val[maxn][maxn], dp[maxn][maxn];

void dfs(int l, int r, int v){
	if(l > r)return;
	parent[opt[l][r]] = v;
	dfs(l, opt[l][r] - 1, opt[l][r]);
	dfs(opt[l][r] + 1, r, opt[l][r]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		total[i] = 0;
		for(int j = 1; j <= n; j++){
			cin >> cost[i][j];
			total[i] += cost[i][j];
		}
	}
	for(int i = 1; i <= n; i++){
		val[i][i] = total[i];
		for(int j = i + 1; j <= n; j++){
			val[i][j] = val[i][j - 1] + total[j];
			for(int k = j - 1; k >= i; k--){
				val[i][j] -= 2*cost[j][k];
			}
		}
	}
	for(int i = 1; i <= n; i++){
		dp[i][i] = 0;
		opt[i][i] = i;
	}
	for(int len = 2; len <= n; len++){
		for(int i = 1, j = len; j <= n; i++, j++){
			if(dp[i][j - 1] + val[i][j - 1] <= dp[i + 1][j] + val[i + 1][j]){
				dp[i][j] = dp[i][j - 1] + val[i][j - 1];
				opt[i][j] = j;
			}else{
				dp[i][j] = dp[i + 1][j] + val[i + 1][j];
				opt[i][j] = i;
			}
			for(int k = i + 1; k <= j - 1; k++){
				if(dp[i][j] > dp[i][k - 1] + dp[k + 1][j] + val[i][k - 1] + val[k + 1][j]){
					dp[i][j] = dp[i][k - 1] + dp[k + 1][j] + val[i][k - 1] + val[k + 1][j];
					opt[i][j] = k;
				}
			}
		}
	}
	dfs(1, n, 0);
	// cout << dp[1][n] << endl;
	for(int i = 1; i <= n; i++){
		cout << parent[i] << ' ';
	}
	cout << '\n';

	return 0;
}