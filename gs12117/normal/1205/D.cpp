#include<cstdio>
#include<vector>
#include<algorithm>
int n;
std::vector<int> el[101000];
int chk[101000];
int sn[101000];
int cent;
int trvt[101000];
int ttime;
int tcolor[101000];
int parent[101000];
struct st {
	int loc, val;
	bool operator<(const st&r)const {
		return val < r.val;
	}
};
void dfs(int x) {
	chk[x] = 1;
	sn[x] = 1;
	for (int i = 0; i < el[x].size(); i++) {
		if (chk[el[x][i]] == 0) {
			dfs(el[x][i]);
			sn[x] += sn[el[x][i]];
		}
	}
	if (cent == 0 && sn[x] > n / 2)cent = x;
}
void trav(int x, int c, int p) {
	chk[x] = 1;
	trvt[x] = ttime;
	ttime++;
	tcolor[x] = c;
	parent[x] = p;
	for (int i = 0; i < el[x].size(); i++) {
		if (chk[el[x][i]] == 0) {
			trav(el[x][i], c, x);
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		el[x].push_back(y);
		el[y].push_back(x);
	}
	dfs(1);
	for (int i = 0; i <= n; i++) {
		chk[i] = 0;
	}
	dfs(cent);
	std::vector<st> z;
	for (int i = 0; i < el[cent].size(); i++) {
		st p;
		p.loc = el[cent][i];
		p.val = sn[el[cent][i]];
		z.push_back(p);
	}
	std::sort(z.begin(), z.end());
	int sumd = 1;
	int asz = 0;
	for (int i = 0; i < z.size(); i++) {
		if (sumd + z[i].val > n - sumd) {
			asz = i;
			break;
		}
		sumd += z[i].val;
	}
	for (int i = 0; i <= n; i++) {
		chk[i] = 0;
	}
	ttime = 1;
	chk[cent] = 1;
	for (int i = 0; i < asz; i++) {
		trav(z[i].loc, 0, cent);
	}
	ttime = 0;
	for (int i = asz; i < z.size(); i++) {
		trav(z[i].loc, 1, cent);
	}
	for (int i = 1; i <= n; i++) {
		if (tcolor[i] == 1) {
			trvt[i] *= sumd;
			trvt[i]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (i != cent) {
			printf("%d %d %d\n", i, parent[i], trvt[i] - trvt[parent[i]]);
		}
	}
	return 0;
}