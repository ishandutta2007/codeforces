#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <long long, long long> pll;
typedef pair <pll, int> ppp;

int a[100010], A[100010], V[100010], cur[100010], ID[100010], OP[100010];
int f[100010];
vector <long long> add[100010];
vector <ppp> all;
vector <int> ans;

bool CCC(int x, int y) {
	return OP[x] < OP[y];
}

bool cmp(ppp a, ppp b) {
	return a.fi.fi * b.fi.se > a.fi.se * b.fi.fi;
}

bool CMP(int x, int y) {
	return V[x] > V[y];
}

int main () {
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	memset(A, -1, sizeof(A));
	for (int i = 0; i < m; i++) {
		int op, x, v; scanf("%d%d%d", &op, &x, &v);
		OP[i] = op;
		V[i] = v;
		if (op == 1) {
			if (A[x] < v) A[x] = v, ID[x] = i;
		} else if (op == 2) add[x].push_back(i);
		else if (op == 3) all.push_back(mp(mp(v - 1, 1), i));
	}
	for (int i = 1; i <= n; i++) {
		if (A[i] != -1 && A[i] > a[i]) V[ID[i]] = A[i] - a[i], add[i].push_back(ID[i]);
		sort(add[i].begin(), add[i].end(), CMP);
		long long cur = a[i];
		for (int j = 0; j < add[i].size(); j++) {
			all.push_back(mp(mp(V[add[i][j]], cur), add[i][j]));
			cur += V[add[i][j]];
		}
	}
	sort(all.begin(), all.end(), cmp);
	for (int i = 0; i < k; i++) {
		if (i == all.size()) break;
		ans.push_back(all[i].se);
	}
	sort(ans.begin(), ans.end(), CCC);
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i] + 1);
	}
	printf("\n");
	return 0;
}