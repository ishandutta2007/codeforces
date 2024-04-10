#include<cstdio>
#include<vector>
#include<map>
using namespace std;
int n, m, q;
vector<int> el[100100];
int cn;
int clr[100100];
int chk[100100];
int prt[100100];
int sdist[100100];
vector<int> dl[100100];
vector<int> sdl[100100];
vector<int> nsdl[100100];
vector<long long int> ssdl[100100];
int md[100100];
map<pair<int, int>, double> dptable;
void dfs(int x, int c) {
	if (chk[x] != 0)return;
	chk[x] = 1;
	clr[x] = c;
	sdist[x] = 0;
	for (int i = 0; i < el[x].size(); i++) {
		if (chk[el[x][i]] == 0) {
			prt[el[x][i]] = x;
			dfs(el[x][i], c);
			if (sdist[x] < sdist[el[x][i]] + 1)sdist[x] = sdist[el[x][i]] + 1;
		}
	}
}
void sdfs(int x, int c, int rdist) {
	if (chk[x] == 2)return;
	chk[x] = 2;
	int dst = rdist;
	if (dst < sdist[x])dst = sdist[x];
	dl[c].push_back(dst);
	int sdp, sdpl, sds;
	sdp = -99;
	sdpl = -99;
	sds = -99;
	for (int i = 0; i < el[x].size(); i++) {
		if (prt[el[x][i]] == x) {
			if (sdp < sdist[el[x][i]] + 1) {
				sds = sdp;
				sdp = sdist[el[x][i]] + 1;
				sdpl = el[x][i];
			}
			else if (sds < sdist[el[x][i]] + 1) {
				sds = sdist[el[x][i]] + 1;
			}
		}
	}
	for (int i = 0; i < el[x].size(); i++) {
		if (prt[el[x][i]] == x) {
			int prdist = rdist;
			if (sdpl == el[x][i]) {
				if (prdist < sds)prdist = sds;
			}
			else {
				if (prdist < sdp)prdist = sdp;
			}
			sdfs(el[x][i], c, prdist + 1);
		}
	}
}
double rcalc(int a, int b) {
	if (sdl[a].size() > sdl[b].size())return rcalc(b, a);
	double ans = 0;
	int smax = md[a];
	if (smax < md[b])smax = md[b];
	long long int td = dl[a].size();
	td *= dl[b].size();
	for (int i = 0; i < sdl[a].size(); i++) {
		int pd = smax - i;
		if (pd < 0)pd = 0;
		if (pd >= sdl[b].size())continue;
		td -= ((long long int)sdl[a][i])*nsdl[b][pd];
		ans += ((double)sdl[a][i]) * ssdl[b][pd];
		ans += ((double)sdl[a][i])*(i + 1)*nsdl[b][pd];
	}
	ans += ((double)smax)*td;
	ans /= dl[a].size();
	ans /= dl[b].size();
	return ans;
}
double calc(int a, int b) {
	if (a < b)return calc(b, a);
	if (dptable.find(make_pair(a, b)) != dptable.end()) {
		return dptable[make_pair(a, b)];
	}
	return dptable[make_pair(a, b)] = rcalc(a, b);
}
int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		el[a].push_back(b);
		el[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (chk[i] == 0) {
			dfs(i, cn);
			sdfs(i, cn, 0);
			md[cn] = 0;
			for (int j = 0; j < dl[cn].size(); j++) {
				if (md[cn] < dl[cn][j])md[cn] = dl[cn][j];
			}
			sdl[cn].resize(md[cn] + 1);
			nsdl[cn].resize(md[cn] + 1);
			ssdl[cn].resize(md[cn] + 1);
			for (int j = 0; j < sdl[cn].size(); j++) {
				sdl[cn][j] = 0;
				nsdl[cn][j] = 0;
				ssdl[cn][j] = 0;
			}
			for (int j = 0; j < dl[cn].size(); j++) {
				sdl[cn][dl[cn][j]]++;
			}
			for (int j = md[cn]; j >= 0; j--) {
				nsdl[cn][j] = sdl[cn][j];
				ssdl[cn][j] = ((long long int)j)*sdl[cn][j];
				if (j != md[cn]) {
					nsdl[cn][j] += nsdl[cn][j + 1];
					ssdl[cn][j] += ssdl[cn][j + 1];
				}
			}
			cn++;
		}
	}
	for (int i = 0; i < q; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (clr[a] == clr[b])printf("-1\n");
		else printf("%.10lf\n", calc(clr[a], clr[b]));
	}
	return 0;
}