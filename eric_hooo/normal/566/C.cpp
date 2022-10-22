#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int n;
int a[200010];
vector <pii> G1[200010];
vector <int> G2[200010];
vector <int> node;
int sz[200010], maxj[200010];

double GetVal(int x, int last, int dep) {
	double ans = pow(dep, 1.5) * a[x];
	for (auto it : G1[x]) {
		int v = it.fi, w = it.se;
		if (v == last) continue;
		ans += GetVal(v, x, dep + w);
	}
	return ans;
}

double GetDif(int x, int last, int dep) {
	double ans = 1.5 * pow(dep, 0.5) * a[x];
	for (auto it : G1[x]) {
		int v = it.fi, w = it.se;
		if (v == last) continue;
		ans += GetDif(v, x, dep + w);
	}
	return ans;
}

void GetSz(int x, int last) {
	node.push_back(x), sz[x] = 1, maxj[x] = -1;
	for (auto v : G2[x]) if (v != last) {
		GetSz(v, x), maxj[x] = max(maxj[x], sz[v]), sz[x] += sz[v];
	}
}

int GetRt(int rt) {
	node.clear(), GetSz(rt, rt);
	for (auto x : node) {
		maxj[x] = max(maxj[x], (int)node.size() - sz[x]);
		if (maxj[x] * 2 <= node.size()) return x;
	}
	assert(0);
	return -1;
}

void CutEdge(int x, int y) {
	G2[x].erase(find(G2[x].begin(), G2[x].end(), y));
}

vector <int> Solve(int rt) {
	rt = GetRt(rt);
	if (node.size() == 2) return {rt, G2[rt][0]};
	double sum = GetDif(rt, rt, 0);
	for (auto it : G1[rt]) {
		int x = it.fi, w = it.se;
		double val = GetDif(x, rt, w);
		if (sum - 2 * val < 0) {
			G2[rt].clear(), G2[rt].push_back(x);
			return Solve(rt);
		}
	}
	return {rt};
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i < n; i++) {
		int x, y, w; scanf("%d%d%d", &x, &y, &w);
		G1[x].push_back(mp(y, w));
		G1[y].push_back(mp(x, w));
		G2[x].push_back(y);
		G2[y].push_back(x);
	}
	vector <int> qwq = Solve(1);
	int rt = -1; double minj = 1e100;
	for (auto x : qwq) {
		double val = GetVal(x, x, 0);
		if (val < minj) minj = val, rt = x;
	}
	printf("%d %.10f\n", rt, minj);
	return 0;
}