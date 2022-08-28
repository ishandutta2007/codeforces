#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 1010;

int ga(int b) {
	printf("B %d\n", b);
	fflush(stdout);
	int a;
	scanf("%d", &a);
	return a;
}

int gb(int a) {
	printf("A %d\n", a);
	fflush(stdout);
	int b;
	scanf("%d", &b);
	return b;
}

vector<int> g[N];
bool vx[N], vy[N], vis[N];
vector<int> x, y;

void solve() {
	int n;
	scanf("%d", &n);
	fill(g, g + N, vector<int>());
	for (int rep = 1; rep < n; ++rep) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	memset(vx, 0, sizeof(vx));
	memset(vy, 0, sizeof(vy));
	int k1;
	scanf("%d", &k1);
	x.resize(k1);
	for (int rep = 0; rep < k1; ++rep) {
		scanf("%d", &x[rep]);
		vx[x[rep]] = true;
	}
	int k2;
	scanf("%d", &k2);
	y.resize(k2);
	for (int rep = 0; rep < k2; ++rep) {
		scanf("%d", &y[rep]);
		vy[y[rep]] = true;
	}
	int rt = ga(y[0]);
	memset(vis, 0, sizeof(vis));
	queue<int> que;
	que.push(rt);
	vis[rt] = true;
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		if (vx[u]) {
			if (vy[gb(u)])
				printf("C %d\n", u);
			else
				puts("C -1");
			fflush(stdout);
			return;
		}
		for (int v : g[u])
			if (!vis[v]) {
				vis[v] = true;
				que.push(v); 
			}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}