#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
 

using namespace std;


int n, k;
long long d[50000][501];
vector<int> v[100000];
int pr[100000];
bool used[100000];


void dfs(int u, int f) {
	pr[u] = f;
	used[u] = true;
	d[u][0] = 1;
	for (int j = 0; j < (int)v[u].size(); j++) {
		int g = v[u][j];
		if (!used[g]) {
			dfs(g, u);
			for (int h = 1; h <= k; h++) {
				d[u][h] += (h - 1 == 0 ? 1LL: d[g][h - 1]);
			}
		}
	}
}


int main() {
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a - 1].push_back(b - 1);
		v[b - 1].push_back(a - 1);
	}
	dfs(0, -1);
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += d[i][k];
		long long sum1 = 0;
		for (int j = 0; j < (int)v[i].size(); j++) {
			int h = v[i][j];
			if (h != pr[i]) {
				for (int k1 = 1; k1 < k; k1++) {
					sum1 += d[h][k1 - 1] * (d[i][k - k1] - d[h][k - k1 - 1]);
				}
			}
		}
		sum1 /= 2LL;
		sum += sum1;
	}
	cout << sum << endl;
	return 0;
}