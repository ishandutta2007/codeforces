#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

const int MAXN = 200;
const int MAXV = 400;

const int V = 310;

int N;
int T;

int A[MAXV];

int dp[MAXV][MAXV];
int res[MAXV][MAXV];
int tmp[MAXV][MAXV];

void mult(int a[MAXV][MAXV], int b[MAXV][MAXV]) {
	for(int i = 0; i < V; i++) {
		for(int j = i; j < V; j++) {
			tmp[i][j] = 0;
			for(int k = i; k <= j; k++) {
				tmp[i][j] = max(tmp[i][j], a[i][k] + b[k][j]);
			}
		}
	}
	for(int i = 0; i < V; i++) {
		for(int j = i; j < V; j++) {
			a[i][j] = tmp[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	cin >> T;
	memset(dp, 0, sizeof(dp));
	memset(res, 0, sizeof(res));
	for(int t = 0; t < N; t++) {
		int v; cin >> v;
		for(int i = 0; i <= v; i++) {
			int cnt = 0;
			for(int j = i; j <= v; j++) {
				cnt = max(cnt, dp[i][j]);
			}
			dp[i][v] = max(dp[i][v], cnt + 1);
		}
	}
	while(T) {
		if(T % 2) {
			mult(res, dp);
		}
		mult(dp, dp);
		T /= 2;
	}
	int ans = 0;
	for(int i = 0; i < V; i++) {
		for(int j = i; j < V; j++) {
			ans = max(ans, res[i][j]);
		}
	}
	cout << ans << '\n';
	return 0;
}