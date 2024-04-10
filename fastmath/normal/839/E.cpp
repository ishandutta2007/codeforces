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
const int MAXN = 50;
const int MAX_MASK = 2e6;
typedef long long ll;

bool g[MAXN][MAXN];
int dp[MAX_MASK];

signed main(){
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n;
	double k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cin >> g[i][j];
		}
	}

	int sz1 = n / 2;
	dp[0] = 0;
	for (int mask = 1; mask < (1 << sz1); ++mask){
		int u = -1;

		for (int i = 0; i < sz1; ++i){
			if ((mask >> i) & 1){
				u = i;
			}
		}

		int mask1 = 0;

		for (int i = 0; i < sz1; ++i){
			if (((mask >> i) & 1) && g[u][i]){
				mask1 |= (1 << i);
			}
		}

		dp[mask] = max(dp[mask ^ (1 << u)], dp[mask1] + 1);
	}

	int sz2 = (n + 1) / 2;
	double max_sz = 0;
	for (int mask2 = 0; mask2 < (1 << sz2); ++mask2){
		vector <int> subgraph;
		for (int u = 0; u < sz2; ++u){
			if ((mask2 >> u) & 1){
				subgraph.push_back(u + sz1);
			}
		}

		bool is_click = true;
		for (int i = 0; i < subgraph.size(); ++i){
			for (int j = i + 1; j < subgraph.size(); ++j){
				is_click &= g[subgraph[i]][subgraph[j]];
			}
		}

		if (!is_click){
			continue;
		}

		int mask = 0;
		for (int u = 0; u < sz1; ++u){
			bool good = true;
			for (int v : subgraph){
				good &= g[u][v];
			}

			if (good){
				mask |= (1 << u);
			}
		}

		max_sz = max(max_sz, (double)subgraph.size() + dp[mask]);
	}

	cout << (k / max_sz) * (k / max_sz) * ((max_sz * (max_sz - 1)) / 2) << '\n';

	return 0;
}