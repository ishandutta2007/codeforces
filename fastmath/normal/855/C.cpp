#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <random>

using namespace std;

void pass(){
	return;
}

#define int long long
#define rand() (rand()<<15+rand())
typedef long long ll;
typedef unsigned long long ull;
const double EPS = 1e-6;

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 1e5 + 7;

int dp[MAXN][3][25], dp1[MAXN][3][25];
vector <int> g[MAXN];
bool used[MAXN];
int n, m, k, x;

int form(int n){
	if (n < 0) return n + MOD;
	if (n >= MOD) return n - MOD;
	return n;
}

int sum(int a, int b){
	return form(a + b);
}

int sum(int a, int b, int c){
	return form(a + sum(b, c));
}

int fact(int a, int b){
	return form((a * b) % MOD);
}

void dfs(int u){
	used[u] = true;

	dp[u][0][0] = k - 1;
	dp[u][1][1] = 1;
	dp[u][2][0] = m - k;

	for (int v : g[u]){
		if (used[v]) continue;

		dfs(v);

		for (int i = 0; i <= x; ++i){
			dp1[u][0][i] = 0;
			dp1[u][1][i] = 0;
			dp1[u][2][i] = 0;
		}

		for (int i = 0; i <= x; ++i){
			for (int j = 0; j <= x; ++j){
				int p0 = dp[v][0][j];
				int p1 = dp[v][1][j];
				int p2 = dp[v][2][j];

				dp1[u][0][i + j] = sum(dp1[u][0][i + j], fact(dp[u][0][i], sum(p0, p1, p2)));
				dp1[u][1][i + j] = sum(dp1[u][1][i + j], fact(dp[u][1][i], p0));
				dp1[u][2][i + j] = sum(dp1[u][2][i + j], fact(dp[u][2][i], sum(p0, p2)));
				pass();
			}
		}

		for (int i = 0; i <= x; ++i){
			dp[u][0][i] = dp1[u][0][i];
			dp[u][1][i] = dp1[u][1][i];
			dp[u][2][i] = dp1[u][2][i];

			dp1[u][0][i] = 0;
			dp1[u][1][i] = 0;
			dp1[u][2][i] = 0;
		}
	}
}


signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	int u, v;
	for (int i = 0; i < n - 1; ++i){
		cin >> u >> v;
		g[u - 1].push_back(v - 1);
		g[v - 1].push_back(u - 1);
	}

	cin >> k >> x;
	dfs(0);

	int ans = 0;
	for (int i = 0; i <= x; ++i){
		ans = sum(ans, sum(dp[0][0][i], dp[0][1][i], dp[0][2][i]));
	}

	cout << ans << '\n';
	return 0;
}