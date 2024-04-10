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
#define rand() rand()<<15+rand()
typedef long long ll;
typedef unsigned long long ull;
const double EPS = 1e-6;

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 1e6 + 7;

vector <int> g[MAXN];
int go[MAXN];
int dp[MAXN];
bool live[MAXN];
bool used[MAXN], used1[MAXN];
bool have_anc[MAXN];
bool bad[MAXN];

int form(int n){
	if (n < 0) return n + MOD;
	if (n >= MOD) return n - MOD;
	return n;
}

int sum(int a, int b){
	return form(a + b);
}

int fact(int a, int b){
	return form((a * b) % MOD);
}

void dfs1(int u){
	dp[u] = 1;
	used[u] = true;
	for (int v : g[u]){
		dfs1(v);
		dp[u] = sum(dp[u], dp[v]);
	}
}

void dfs2(int u){
	used[u] = true;
	for (int v : g[u]){
		if (!used[v]) dfs2(v);
	}
}

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int u, v;
	for (int i = 0; i < n; ++i){
		cin >> u >> v;
		if (u == v) bad[u] = true;

		live[u] = true;
		have_anc[v] = true;
		go[u] = v;
		g[v].push_back(u);
	}

	int ans = 1;
	for (int i = 1; i <= 2 * n; ++i){
		if ((!bad[i]) && (!live[i]) && (have_anc[i])){
			dfs1(i);
			ans = fact(ans, dp[i]);
		}
	}

	for (int i = 1; i <= 2 * n; ++i){
		if ((!bad[i]) && (live[i]) && (!used[i])){

			int u = i;
			while (!used1[go[u]]){
				used1[u] = true;
				u = go[u];
			}

			if (go[u] != u) ans = fact(ans, 2);
			dfs2(u);
		}
	}

	cout << ans << '\n';
	return 0;
}