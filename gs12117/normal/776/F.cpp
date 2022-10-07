#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;
set<int> diag[100100];
map<pair<int, int>, int> dcolor;
vector<int> pl[100100];
int n, m;
vector<int> bel[100100];
vector<int> el[100100];
int cn;
int ans[100100];
int chk[100100];
int psn[100100];
int sn[100100];
struct cmpst {
	int p;
	bool operator<(const cmpst&r)const {
		return pl[p] < pl[r.p];
	}
};
cmpst renumb[100100];
int aren[100100];
int cent;
void color(int a, int b) {
	while (dcolor.find(make_pair(a, b)) == dcolor.end()) {
		pl[cn].push_back(a);
		dcolor[make_pair(a, b)] = cn;
		auto ite = diag[b].find(a);
		ite++;
		if (ite == diag[b].end())ite = diag[b].begin();
		a = b;
		b = *ite;
	}
}
void dfs(int x) {
	psn[x] = 1;
	for (int i = 0; i < el[x].size(); i++) {
		if (ans[el[x][i]] != 0 || psn[el[x][i]] != 0)continue;
		dfs(el[x][i]);
		psn[x] += psn[el[x][i]];
	}
}
void cdfs(int x, int p) {
	sn[x] = 1;
	for (int i = 0; i < el[x].size(); i++) {
		if (ans[el[x][i]] != 0 || sn[el[x][i]] != 0)continue;
		cdfs(el[x][i], p);
		sn[x] += sn[el[x][i]];
	}
	if (sn[x] * 2 >= p&&cent == -1)cent = x;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		diag[a].insert(b);
		diag[b].insert(a);
	}
	for (int i = 1; i <= n; i++) {
		int p = i%n + 1;
		diag[i].insert(p);
		diag[p].insert(i);
	}
	cn = 0;
	for (int i = 1; i <= n; i++) {
		for (auto p : diag[i]) {
			if (dcolor.find(make_pair(i, p)) == dcolor.end()) {
				color(i, p);
				cn++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (auto p : diag[i]) {
			if (dcolor.find(make_pair(i, p)) == dcolor.end()) {
				color(i, p);
				cn++;
			}
			if ((*dcolor.find(make_pair(i, p))).second == 0 || (*dcolor.find(make_pair(p, i))).second == 0)continue;
			bel[(*dcolor.find(make_pair(i, p))).second].push_back((*dcolor.find(make_pair(p, i))).second);
		}
	}
	n = cn - 1;
	for (int i = 1; i <= n; i++) {
		sort(pl[i].begin(), pl[i].end(), greater<int>());
		renumb[i - 1].p = i;
	}
	std::sort(renumb, renumb + n);
	for (int i = 0; i < n; i++) {
		aren[renumb[i].p] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (auto &a : bel[i]) {
			el[aren[i]].push_back(aren[a]);
		}
	}
	for (int p = 1;; p++) {
		int flag = 0;
		for (int i = 0; i < n; i++) {
			chk[i] = 0;
			sn[i] = 0;
			psn[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			if (ans[i] == 0&&sn[i]==0) {
				flag = 1;
				cent = -1;
				dfs(i);
				cdfs(i, psn[i]);
				ans[cent] = p;
			}
		}
		if (flag == 0)break;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}