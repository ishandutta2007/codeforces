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

int p[MAXN], h[MAXN];
bool is_anc_lower[MAXN];
vector <int> g[MAXN];
int cost[MAXN], dp[MAXN];
bool used[MAXN];
int t;
vector <int> good;

void dfs(int u, int deep){
	h[u] = deep;
	used[u] = true;
	dp[u] = cost[u];

	for (int v : g[u]){
		if (!used[v]){
			dfs(v, deep + 1);
			dp[u] += dp[v];
		}
	}
}

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n;
	scanf("%I64d\n", &n);
	int sum = 0;
	int root;
	for (int i = 0; i < n; ++i){
		scanf("%I64d %I64d\n", &p[i], &cost[i]);
		sum += cost[i];
		p[i]--;

		if (p[i] == -1) {
			root = i;
			continue;
		}

		g[i].push_back(p[i]);
		g[p[i]].push_back(i);
	}

	if (sum % 3){
		cout << "-1\n";
		return 0;
	}

	t = sum / 3;
	dfs(root, 0);
	
	for (int i = 0; i < n; ++i){
		if (dp[i] == t){
			good.push_back(i);
		}
	}

	int k = good.size();

	if (!k){
		cout << "-1\n";
		return 0;
	}

	int lower = good[0];
	for (int i = 0; i < k; ++i){
		if (h[good[i]] > h[lower]){
			lower = good[i];
		}
	}

	int u = lower;
	while (u != -1){
		if (u != root && u != lower && dp[u] == 2 * t){
			cout << lower + 1 << ' ' << u + 1 << '\n';
			return 0;
		}

		is_anc_lower[u] = true;
		u = p[u];
	}

	for (int i = 0; i < k; ++i){
		if (!is_anc_lower[good[i]]){
			cout << lower + 1 << ' ' << good[i] + 1 << '\n';
			return 0;
		}
	}

	cout << "-1\n";
	return 0;
}