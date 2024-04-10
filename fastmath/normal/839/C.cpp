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

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const long long BIG_MOD = 1e18 + 7;
const int MAXN = 1e5 + 7;
typedef long long ll;

vector <int> g[MAXN];
double dp[MAXN];

void dfs(int u, int h, int prev){
	int p = 0;
	for (int v : g[u]){
		if (v != prev){
			dfs(v, h + 1, u);
			dp[u] += dp[v];
			++p;
		}
	}

	if (!p){
		dp[u] = h;
	}
	else{
		dp[u] /= p;
	}
}

signed main(){
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int u, v;
	for (int i = 0; i < n - 1; ++i){
		cin >> u >> v;
		g[u - 1].push_back(v - 1);
		g[v - 1].push_back(u - 1);
	}

	dfs(0, 0, -1);

	cout << dp[0] << '\n';
	return 0;
}