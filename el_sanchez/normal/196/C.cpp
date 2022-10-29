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

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.0000001;
const int INF = 1E9;
const int MAXN = 2000;

struct pt {
    int64 x, y;
	int id;
	pt(): x(0), y(0), id(0) {}
	pt(int64 a, int64 b, int c) {
		x = a, y = b, id = c;
	}
};

int n, aa, bb, dp[MAXN], id[MAXN];
bool use[MAXN], use2[MAXN];
vector<int> w[MAXN];
int64 a, b, x;
pt root, wa, wb;
pt ww[MAXN];

void dfs(int v) {
	use[v] = 1;
	dp[v] = 1;
	int z;
	forn(i, w[v].size()) {
		z = w[v][i];
		if (!use[z]) {
			dfs(z);
			dp[v] += dp[z];
		}
	}
}

int cmp1(pt a, pt b) {
	if (a.y != b.y) return (a.y < b.y);
	return (a.x < b.x);
}

int cmp2(pt a, pt b) {
	return (a.x - root.x) * (b.y - root.y) - (a.y - root.y) * (b.x - root.x) > 0;
}

void dfs2(int v, int l, int r) {
	use2[v] = 1;
	FORN(i, l, r)
		if (!cmp1(ww[l - 1], ww[i]))
			swap(ww[l - 1], ww[i]);
	root = ww[l - 1];
	id[ww[l - 1].id] = v;
	sort(ww + l, ww + r + 1, cmp2);

	int z, cdp = 0;
	forn(i, w[v].size()) {
		z = w[v][i];
		if (!use2[z]) {
			dfs2(z, l + cdp + 1, l + cdp + dp[z] - 1);
			cdp += dp[z];
		}
	}
}

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> n;
	forn(i, n - 1) {
		cin >> aa >> bb;
		aa--, bb--;
		w[aa].push_back(bb);
		w[bb].push_back(aa);
	}
	forn(i, n) {
		cin >> a >> b;
		ww[i] = pt(a, b, i);
	}

	dfs(0);
	dfs2(0, 1, n - 1);

	forn(i, n)
		cout << id[i] + 1 << ' ';
	cout << '\n';

	return 0;
}