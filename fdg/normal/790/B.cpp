#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

vector<int> g[200002];

int n, k;

long long total = 0;

pair<long long, vector<long long> > out[200002];

pair<long long, vector<long long> > dfs(int v, int p = -1) {
	long long ans = 0;
	vector<long long> rem(k);

	for (int i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (u == p) continue;

		pair<long long, vector<long long> > tmp = dfs(u, v);
		tmp.second[0]++;
		ans += tmp.first;
		for (int j = 0; j < k; ++j) {
			if (j + 1 == k) {
				ans += tmp.second[j];
				rem[0] += tmp.second[j];
			} else {
				rem[j + 1] += tmp.second[j];
			}
		}
	}

	// total += ans;
	// int s = 0;
	// for (int i = 0; i < k; ++i)
	// 	total += rem[i], s += rem[i];

	// cout << v << "	" << ans << endl;
	// for (int i = 0; i < k; ++i)
	// 	cout << rem[i] << "	";
	// cout << endl << endl;

	out[v] = make_pair(ans, rem);

	// rem[0] += 1;

	return make_pair(ans, rem);
}

void go(int v, int p, pair<long long, vector<long long> > fromP) {
	long long cnt = out[v].first + fromP.first;
	total += out[v].first + fromP.first;
	for (int i = 1; i < k; ++i)
		total += out[v].second[i] + fromP.second[i], cnt += out[v].second[i] + fromP.second[i];
	// cout << v << "	" << cnt << endl;

	long long ans = fromP.first;
	vector<long long> rem = fromP.second;

	for (int i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (u == p) continue;

		ans += out[u].first;
		vector<long long> tmp = out[u].second;
		tmp[0]++;
		for (int j = 0; j < k; ++j) {
			if (j + 1 == k) {
				ans += tmp[j];
				rem[0] += tmp[j];
			} else {
				rem[j + 1] += tmp[j];
			}
		}
	}

	for (int i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (u == p) continue;

		long long ans2 = ans;
		vector<long long> rem2 = rem;

		ans2 -= out[u].first;
		// for (int j = 0; j < k; ++j) {
		// 	if (j + 1 == k) {
		// 		ans2 -= out[u].second[j];
		// 		rem2[0] -= out[u].second[j];
		// 	} else {
		// 		rem2[j + 1] -= out[u].second[j];
		// 	}
		// }
		// rem2[1]--;

		vector<long long> tmp = out[u].second;
		tmp[0]++;
		for (int j = 0; j < k; ++j) {
			if (j + 1 == k) {
				ans2 -= tmp[j];
				rem2[0] -= tmp[j];
			} else {
				rem2[j + 1] -= tmp[j];
			}
		}
	
		long long ans3 = ans2;
		vector<long long> rem3(k);
		rem2[0]++;

		for (int j = 0; j < k; ++j) {
			if (j + 1 == k) {
				ans3 += rem2[j];
				rem3[0] += rem2[j];
			} else {
				rem3[j + 1] = rem2[j];
			}
		}

		go(u, v, make_pair(ans3, rem3));
	}
}

int main() {
	ios::sync_with_stdio(false);

	// freopen("input.txt", "r", stdin);

	cin >> n >> k;
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(0);
	go(0, -1, make_pair(0, vector<long long>(k)));
	cout << total / 2 << endl;

	return 0;
}