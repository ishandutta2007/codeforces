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


#define INF 2000000000
#define MAXN 500


struct edge{
    int tg;
    int flow;
    int cap;
    int back;
    edge(){}
    edge(int tg, int flow, int cap, int back) : tg(tg), flow(flow), cap(cap), back(back) {}
};



int n, m;
int a[MAXN];
int b[MAXN];
vector<edge> v[MAXN];
int ans[MAXN][MAXN];
int ssum = 0;
bool used[MAXN];


void add(int u, int g, int c) {
    edge e1(g, 0, c, (int)v[g].size());
    edge e2(u, 0, 0, (int)v[u].size());
    v[u].push_back(e1);
    v[g].push_back(e2);
}


int dfs(int u, int ms) {
	used[u] = true;
	if (u == 2 * n + 1) {
		return ms;
	}
	for (int j = 0; j < (int)v[u].size(); j++) {
		int g = v[u][j].tg;
		if (!used[g] && v[u][j].cap - v[u][j].flow > 0) {
			int t = dfs(g, min(ms, v[u][j].cap - v[u][j].flow));
			if (t == 0) {
				continue;
			}
			v[u][j].flow += t;
			v[g][v[u][j].back].flow -= t;
			return t;
		}
	}
	return 0;
}


int main() {
	cin >> n >> m;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		ans[i][i] = a[i];
	}
	int sum1 = 0;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		sum1 += b[i];
	}
	if (sum != sum1) {
		cout << "NO" << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		add(0, i + 1, a[i]);
	}
	for (int i = 0; i < n; i++) {
		add(n + i + 1, 2 * n + 1, b[i]);
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--;b--;
		add(a + 1, b + n + 1, INF);
		add(b + 1, a + n + 1, INF);
	}
	for (int i = 0; i < n; i++) {
		add(i + 1, i + n + 1, INF);
	}
	while (true) {
		memset(used, 0, sizeof(used));
		int t = dfs(0, INF);
		ssum += t;
		if (!t) {
			break;
		}
	}
//	cout << ssum << endl;
	if (ssum != sum) {
		cout << "NO" << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < (int)v[i].size(); j++) {
			int x = v[i][j].tg;
			if (x > n && x <= 2 * n) {
				ans[i - 1][x - n - 1] = INF - (v[i][j].cap - v[i][j].flow);
			}
		}
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}