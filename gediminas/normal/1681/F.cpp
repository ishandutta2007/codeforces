#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

/*input
3
1 2 1
1 3 2
*/
/*input
3
1 2 2
1 3 2
*/
/*input
5
1 4 4
1 2 3
3 4 4
4 5 5
*/
/*input
2
2 1 1
*/
/*input
10
10 2 3
3 8 8
4 8 9
5 8 5
3 10 7
7 8 2
5 6 6
9 3 4
1 6 3
*/

const int maxn = 500100;
const int max2n = 2 * maxn;
int n;
vector<pair<int, int>> gra[maxn];
vector<int> gra2[maxn];
long long ans = 0;
int timer = 0;
int tst[max2n], tend[max2n];
vector<int> colv[maxn];
vector<int> nodes;
int sz[maxn];

void dfs(int v, int p) {
	tst[v] = timer++;
	sz[v] = 1;

	for (auto [i, cc] : gra[v]) {
		if (i == p) {
			continue;
		}

		colv[cc].push_back(i);
		dfs(i, v);
		sz[v] += sz[i];
	}

	tend[v] = timer++;
}

int nodep = 0;
void buildgr(int v) {
	gra2[v] = {};

	while (nodep < nodes.size() and tend[nodes[nodep]] < tend[v]) {
		gra2[v].push_back(nodes[nodep]);
		buildgr(nodes[nodep++]);
	}
}

long long din(int v) {
	long long nul = 1, saiz = sz[v];

	for (auto i : gra2[v]) {
		saiz -= sz[i];
	}

	for (auto i : gra2[v]) {
		auto t = din(i);
		ans += t * saiz;
	}

	return saiz;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;

	for (int i = 1; i < n; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--, c--;
		gra[a].push_back({b, c});
		gra[b].push_back({a, c});
	}

	dfs(0, 0);

	for (int i = 0; i < n; ++i) {
		if (colv[i].empty()) {
			continue;
		}

		nodes = colv[i];
		nodep = 0;
		buildgr(0);
		din(0);
	}

	cout << ans;
}