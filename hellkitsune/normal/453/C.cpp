#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
vector<int> g[100000];
int z[100000];
vector<int> ans;
bool vis[100000] = {};
bool flag2 = false;

void dfs(int v, int p) {
	ans.pb(v);
	vis[v] = true;
	z[v] ^= 1;
	REP(i, g[v].size()) if (!vis[g[v][i]]) {
		dfs(g[v][i], v);
		ans.pb(v);
		z[v] ^= 1;
	}
	if (z[v] == 1) {
		if (p == -1) flag2 = true;
		else {
			ans.pb(p);
			ans.pb(v);
			z[v] = 0;
			z[p] ^= 1;
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	REP(i, m) {
		int x, y;
		scanf("%d%d", &x, &y), --x, --y;
		g[x].pb(y);
		g[y].pb(x);
	}
	REP(i, n) scanf("%d", z + i);
	bool flag = true;
	REP(i, n) if (z[i] == 1) {
		if (flag) dfs(i, -1);
		else {
			cout << -1 << endl;
			return 0;
		}
		if (flag2) {
			if (g[i].empty()) {
				cout << -1 << endl;
				return 0;
			} else {
				ans.pb(g[i][0]);
				ans.pb(i);
				ans.pb(g[i][0]);
			}
		}
		flag = false;
	}
	cout << (int)ans.size() << endl;
	REP(i, (int)ans.size()) printf("%d ", ans[i] + 1);
	printf("\n");
	return 0;
}