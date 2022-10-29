#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <complex>
#include <map>
#include <set>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define fi first
#define se second

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> pii;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.0000001;
const int INF = 1E9;
const int MAXN = 3100;

int n, k, l, ans, clr[MAXN], p[MAXN], f[2];
vector<vi> w(MAXN);
bool was[MAXN], inc[MAXN];

bool dfs(int v, int pr){
	clr[v] = 1;
	forn(i, w[v].size()) {
		int to = w[v][i];
		if (pr == to) continue;
		if (clr[to] == 0) {
			p[to] = v;
			if (dfs(to, v)) return 1;
		}
		else if (clr[to] == 1) {
			f[0] = to;
			f[1] = v;
			return 1;
		}
	}
	clr[v] = 2;
	return 0;
}

void dfs2(int v, int c) {
	was[v] = 1;
	if (inc[v]) {
		ans = min(ans, c);
		return;
	}
	forn(i, w[v].size()) {
		int to = w[v][i];
		if (!was[to]) dfs2(to, c + 1);
	}
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif

	cin >> n;
	forn(i, n) {
		cin >> k >> l;
		w[k].push_back(l);
		w[l].push_back(k);
	}
	
	dfs(1, -1);
	inc[f[0]] = 1;
	for (int v = f[1]; v != f[0]; v = p[v])
		inc[v] = 1;

	FORN(i, 1, n) {
		ans = INF;
		memset(was, 0, MAXN);
		dfs2(i, 0);
		cout << ans << ' ';
	}

	return 0;
}