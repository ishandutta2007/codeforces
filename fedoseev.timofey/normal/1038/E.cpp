#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

const int C = 4;
const int Inf = 1e9;

int delta[C];

int w[C][C];
int mn[C][C];
int deg[C];
bool used[C];

int M;

int odd;

vector <int> ord;

void dfs(int u) {
	ord.push_back(u);
	used[u] = 1;
	if (deg[u] % 2) ++odd;
	for (int i = 0; i < C; ++i) {
		if (!used[i] && w[u][i]) {
			dfs(i);
		} 
	}
}

int main() {
	ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cin.tie(0);
	#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	for (int i = 0; i < C; ++i) {
		for (int j = 0; j < C; ++j) {
			mn[i][j] = Inf;
		}
	}
	for (int i = 0; i < n; ++i) {
		int a, v, b;
		cin >> a >> v >> b;
		--a, --b;
		if (a == b) {
			delta[a] += v;
		}
		else {
			w[a][b] += v;
			w[b][a] += v;
			mn[a][b] = min(mn[a][b], v);
			mn[b][a] = min(mn[b][a], v);
			++deg[a];
			++deg[b];
		}
	}
	int ans = 0;
	vector <pair <int, int>> ed;
	for (int i = 0; i < C; ++i) {
		for (int j = i + 1; j < C; ++j) {
			ed.push_back({i, j});
		}
	}
	M = ed.size();
	for (int mask = 0; mask < (1 << M); ++mask) {
		bool fl = true;
		for (int i = 0; i < M; ++i) {
			if ((mask & (1 << i)) && !w[ed[i].first][ed[i].second]) {
				fl = false;
			}
		}
		if (!fl) continue;
		for (int i = 0; i < M; ++i) {
			if (mask & (1 << i)) {
				w[ed[i].first][ed[i].second] -= mn[ed[i].first][ed[i].second];
				w[ed[i].second][ed[i].first] -= mn[ed[i].first][ed[i].second];
				--deg[ed[i].first];
				--deg[ed[i].second];
			}
		}
		for (int i = 0; i < C; ++i) used[i] = 0;
		for (int i = 0; i < C; ++i) {
			if (!used[i]) {
				odd = 0;
				ord.clear();
				dfs(i);
				if (odd <= 2) {
					int cur = 0;
					for (int i = 0; i < ord.size(); ++i) {
						cur += delta[ord[i]];
						for (int j = i + 1; j < ord.size(); ++j) {
							cur += w[ord[i]][ord[j]];
						}	
					}
					ans = max(ans, cur);
				}
			}
		}
		for (int i = 0; i < M; ++i) {
			if (mask & (1 << i)) {
				w[ed[i].first][ed[i].second] += mn[ed[i].first][ed[i].second];
				w[ed[i].second][ed[i].first] += mn[ed[i].first][ed[i].second];
				++deg[ed[i].first];
				++deg[ed[i].second];
			}
		}
	}
	cout << ans << '\n';
}