#pragma comment(linker, "/STACK:67108864")

#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <complex>
#include <bitset>
#include <map>
#include <set>
#include <ctime>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for(int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for(int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 200500; //CHANGE

int n, k, cmp;
vi a;
int g[MAXN][2], clr[MAXN][2], used[MAXN][2];
ll ans, res[MAXN][2];
bool bad[MAXN][2], inclrs[2 * MAXN];
vi gg[MAXN][2];
pii clast;

bool dfs(int v, int k) {
	if (v == -1)
		return 0;
	if (used[v][k] == 1)
		return 1;

	used[v][k] = 1;
	clast.ff = v;
	clast.ss = k;

	int w = g[v][k];
	bool isbad = dfs(w, 1 - k);

	return isbad;
}

void invdfs(int v, int k, ll sum) {
	if (sum == -1)
		bad[v][k] = 1;
	else
		res[v][k] = sum + a[v];
	clr[v][k] = cmp;
	used[v][k] = 2;

	forn(i, gg[v][k].size()) {
		int w = gg[v][k][i];
		if (sum == -1) {
			if (used[w][1 - k] != 2)
				invdfs(w, 1 - k, -1);
		} else
			invdfs(w, 1 - k, sum + a[v]);
	}
}

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	scanf("%d", &n);
	a.pb(0);
	a.pb(0); //we don't know
	for (int i = 2; i <= n; i++) {
		scanf("%d", &k);
		a.pb(k);
	}

	for (int i = 2; i <= n; i++) {
		if (i + a[i] > n)
			g[i][0] = -1;
		else {
			g[i][0] = i + a[i];
			gg[i + a[i]][1].pb(i);
		}

		if (i - a[i] <= 0)
			g[i][1] = -1;
		else {
			g[i][1] = i - a[i];
			gg[i - a[i]][0].pb(i);
		}
	}
	
	cmp = 0;
	for (int i = 2; i <= n; i++)
		forn(j, 2)
			if (used[i][j] == 0) {
				cmp++;
				if (!dfs(i, j)) { //all is okay
					invdfs(clast.ff, clast.ss, 0);
				} else { //all is bad...
					invdfs(clast.ff, clast.ss, -1);
				}
			}

	forn(i, gg[1][0].size())
		inclrs[clr[gg[1][0][i]][1]] = 1;

	for (int i = 1; i <= n - 1; i++) {
		k = clr[1 + i][1];
		if (bad[1 + i][1] || inclrs[k])
			printf("-1\n");
		else
			cout << res[1 + i][1] + i << '\n';
	}

    return 0;
}