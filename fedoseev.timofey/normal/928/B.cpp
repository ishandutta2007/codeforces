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

using namespace std;

typedef long long ll;

const int N = 1e5 + 7;

vector <int> g[N];
int ans[N];
bool used[N];

int n, k;

void dfs(int u, int p) {
	used[u] = 1;
	if (p == -1) {
		int left = max(0, u - k);
		int right = min(n - 1, u + k);
		ans[u] = right - left + 1;
	}
	else {
		int left = max(0, u - k);
		int right = min(n - 1, u + k);
		int was = min(n - 1, p + k);
		left = max(left, was + 1);
		ans[u] = max(0, right - left + 1);
		ans[u] += ans[p];
	}
	for (auto v : g[u]) {
		if (!used[v]) dfs(v, u);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	cin >> n >> k;
	vector <int> a(n);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		--x;
		if (x != -1) {
			g[x].push_back(i);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			dfs(i, -1);
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << " ";
	}
}