#include<cstdio>
#include<string>
#include<map>
#include<vector>
using namespace std;
int n;
char name[1010][2][23];
char tmp[10];
int pn[1010][2];
string p[2010];
map<string, int> invp;
int sn;
int echk[2010];
int nchk[2010];
int pnchk[2010];
int ans[2010];
vector<int> el[2010];
int pe[2];
int pec;
void dfs(int x) {
	int pen = 0;
	pnchk[x] = 2;
	for (int i : el[x]) {
		if (pnchk[i] == 0) {
			dfs(i);
		}
		else {
			pen++;
			if (pen != 1) {
				pe[0] = x;
				pe[1] = i;
				pec++;
			}
		}
	}
	pnchk[x] = 3;
}
void color() {
	while (1) {
		int flag = 0;
		for (int i = 0; i < n; i++) {
			if (echk[i] == 1)continue;
			if (nchk[pn[i][0]] == 1 && nchk[pn[i][1]] == 0) {
				flag = 1;
				ans[i] = 1;
				echk[i] = 1;
				nchk[pn[i][1]] = 1;
			}
			if (nchk[pn[i][1]] == 1 && nchk[pn[i][0]] == 0) {
				flag = 1;
				ans[i] = 0;
				echk[i] = 1;
				nchk[pn[i][0]] = 1;
			}
		}
		if (flag == 0)break;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s%s", name[i][0], name[i][1]);
	}
	tmp[3] = 0;
	for (int i = 0; i < n; i++) {
		tmp[0] = name[i][0][0];
		tmp[1] = name[i][0][1];
		tmp[2] = name[i][0][2];
		string t = tmp;
		if (invp.find(t) == invp.end()) {
			invp[t] = sn;
			p[sn] = t;
			sn++;
		}
		pn[i][0] = invp[t];
		tmp[2] = name[i][1][0];
		t = tmp;
		if (invp.find(t) == invp.end()) {
			invp[t] = sn;
			p[sn] = t;
			sn++;
		}
		pn[i][1] = invp[t];
	}
	color();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j != i&&pn[i][0] == pn[j][0]) {
				echk[i] = 1;
				nchk[pn[i][1]] = 1;
				ans[i] = 1;
			}
		}
	}
	color();
	for (int i = 0; i < n; i++) {
		if (echk[i] == 0) {
			el[pn[i][0]].push_back(pn[i][1]);
			el[pn[i][1]].push_back(pn[i][0]);
		}
	}
	for (int i = 0; i < sn; i++) {
		if (nchk[i] == 0) {
			pec = 0;
			dfs(i);
			for (int j = 0; j < sn; j++) {
				pnchk[j] = 0;
			}
			if (pec > 1) {
				printf("NO\n");
				return 0;
			}
			else if (pec == 0) {
				nchk[i] = 1;
				color();
			}
			else if (pec == 1) {
				int j;
				for (j = 0; j < n; j++) {
					if (echk[j])continue;
					if (pn[j][0] == pe[0] && pn[j][1] == pe[1])break;
					if (pn[j][1] == pe[0] && pn[j][0] == pe[1])break;
				}
				ans[j] = 1;
				nchk[pn[j][1]] = 1;
				echk[j] = 1;
				color();
			}
			dfs(i);
			for (int j = 0; j < sn; j++) {
				if (pnchk[j] >= 2)nchk[j] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (echk[i] != 1) {
			printf("NO\n");
			return 0;
		}
		for (int j = 0; j < n; j++) {
			if (j != i&&pn[i][ans[i]] == pn[j][ans[j]]) {
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	for (int i = 0; i < n; i++) {
		printf("%s\n", p[pn[i][ans[i]]].c_str());
	}
	return 0;
}