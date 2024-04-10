#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int n;
int edge[100100][2];
vector<int> el[100100];
int sn[100100];
int cent;
int chk[100100];
int root[100100];
map<vector<int>, int> mp;
int isom[100100];
int icnt[100100];
int ansl;
long long int ans;
void cdfs(int x) {
	sn[x] = 1;
	for (int i = 0; i < el[x].size(); i++) {
		if (sn[el[x][i]] != 0)continue;
		cdfs(el[x][i]);
		sn[x] += sn[el[x][i]];
	}
	if (sn[x] * 2 >= n&&cent == -1)cent = x;
}
void solve(int x) {
	vector<int> p;
	for (int i = 0; i < el[x].size(); i++) {
		if (root[el[x][i]] != x)continue;
		p.push_back(isom[el[x][i]]);
	}
	std::sort(p.begin(), p.end());
	if (mp[p] == 0)mp[p] = x;
	isom[x] = mp[p];
}
void dfs(int x) {
	chk[x] = 1;
	for (int i = 0; i < el[x].size(); i++) {
		if (chk[el[x][i]] != 0)continue;
		root[el[x][i]] = x;
		dfs(el[x][i]);
	}
	solve(x);
}
void pdfs(int x, long long int d) {
	chk[x] = 1;
	if(icnt[isom[x]] == 2)d += 1;
	if(icnt[isom[x]] > 2)d += 1;
	if (ans < d) {
		ans = d;
		ansl = x;
	}
	for (int i = 0; i < el[x].size(); i++) {
		if (chk[el[x][i]] != 0)continue;
		pdfs(el[x][i], d);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d", &edge[i][0], &edge[i][1]);
		el[edge[i][0]].push_back(edge[i][1]);
		el[edge[i][1]].push_back(edge[i][0]);
	}
	cent = -1;
	cdfs(1);
	dfs(cent);
	for (int i = 1; i <= n; i++) {
		icnt[isom[i]]++;
		chk[i] = 0;
	}
	pdfs(cent, 1);
	printf("%d", ansl);
}