#include<cstdio>
#include<vector>
#include<set>
using namespace std;
int n, m;
vector<int> s[300100];
vector<int> el[300100];
int clr[300100];
set<int> unusd;
int chk[300100];
void dfscolor(int x) {
	if (chk[x] == 1)return;
	chk[x] = 1;
	for (int i = 0; i < s[x].size(); i++) {
		if (clr[s[x][i]] != 0)unusd.erase(clr[s[x][i]]);
	}
	for (int i = 0; i < s[x].size(); i++) {
		if (clr[s[x][i]] == 0) {
			clr[s[x][i]] = *unusd.begin();
			unusd.erase(clr[s[x][i]]);
		}
	}
	for (int i = 0; i < s[x].size(); i++) {
		unusd.insert(clr[s[x][i]]);
	}
	for (int i = 0; i < el[x].size(); i++) {
		dfscolor(el[x][i]);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		int d;
		scanf("%d", &d);
		if (ans < d)ans = d;
		for (int j = 0; j < d; j++) {
			int t;
			scanf("%d", &t);
			s[i].push_back(t);
		}
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		el[a].push_back(b);
		el[b].push_back(a);
	}
	for (int i = 1; i <= ans; i++) {
		unusd.insert(i);
	}
	dfscolor(1);
	printf("%d\n", ans);
	for (int i = 1; i <= m; i++) {
		if (clr[i] == 0)clr[i] = 1;
		printf("%d ", clr[i]);
	}
	return 0;
}