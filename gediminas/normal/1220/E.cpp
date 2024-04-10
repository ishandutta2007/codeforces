/*link https://codeforces.com/contest/1220/problem/E */
/*input
5 7
2 2 8 6 9
1 2
1 3
2 4
3 2
4 5
2 5
1 5
2
*/
/*output
27
*/
/*input
10 12
1 7 1 9 3 3 6 30 1 10
1 2
1 3
3 5
5 7
2 3
5 4
6 9
4 6
3 7
6 8
9 4
9 10
6
*/
/*output
61
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define x first
#define y second

struct UnionFind {
	vector<int> par;
	vector<int> siz;
	vector<ll> val;
	UnionFind(int N) {
		par.resize(N);
		siz.resize(N);
		val.resize(N);

		for (int i = 0; i < N; i++) {
			par[i] = i;
			siz[i] = 1;

			val[i] = i;
		}
	}
	ll &operator[](const int &x) {
		return val[getParent(x)];
	}
	int getParent(int x) {
		int t = x;

		while (par[x] != x)
			x = par[x];

		par[t] = x;
		return x;
	}
	int getSize(const int &x) {
		return siz[getParent(x)];
	}
	bool merge(int x, int y) {
		x = getParent(x);
		y = getParent(y);

		if (x == y)
			return false;

		if (siz[x] > siz[y])
			swap(x, y); // siz[x] is smaller

		par[x] = y;
		siz[y] += siz[x];
		val[y] = val[x] + val[y];
		return true;

	}
	bool connected(const int &x, const int &y) {
		return getParent(x) == getParent(y);
	}
};

using namespace std;
const int maxn = 200000;
UnionFind un(maxn);
vector<pair<int, bool> > gra[maxn];
int nmin[maxn];
int num[maxn];
int timer = 1;
int n, m;

set<pair<int, int>> ats;

void dfs(int d, int p = -1) {
	nmin[d] = num[d] = timer++;

	for (auto && xx : gra[d]) {
		int x = xx.first;

		if (x == p)
			continue;

		if (num[x] != 0)
			nmin[d] = min(nmin[d], num[x]);
		else {
			dfs(x, d);
			nmin[d] = min(nmin[d], nmin[x]);

			if (nmin[x] > num[d]) {
				ats.insert(make_pair(d, x));
				ats.insert(make_pair(x, d));
			}
		}
	}
}

set<int> gra2[maxn];

pll din(int d, int p) {
	pll ret(un[d], un[d]);
	ll mauz = 0;
	bool nuej = false;
	bool galimneuz = false;

	if (un.getSize(d) > 1)
		galimneuz = true;

	for (auto && i : gra2[d]) {
		if (i == p or i == d)
			continue;

		nuej = true;
		pll t = din(i, d);
		ret.x += max(0ll, t.x);
		mauz = max(mauz, t.y - max(0ll, t.x));

		if (t.x >= 0)
			galimneuz = true;
	}

	if (nuej == false) {
		if (un.getSize(d) == 1) {
			return pll{ -1e16, un[d]};
		}
		else {
			return pll{un[d], un[d]};
		}
	}

	ret.y = ret.x + mauz;

	if (ret.x < -1e16 or !galimneuz)
		ret.x = -1e16;

	// cout << d << " " << p << " " << ret.x << " " << ret.y << endl;
	return ret;
}

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> un[i];
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		gra[a].push_back(make_pair(b, false));
		gra[b].push_back(make_pair(a, false));
	}

	for (int i = 0; i < n; i++) {
		if (num[i] == 0)
			dfs(i);
	}

	for (int i = 0; i < n; i++) {
		for (auto && [j, b] : gra[i]) {
			if (!ats.count(make_pair(i, j))) {
				un.merge(i, j);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (auto && [j, b] : gra[i]) {
			if (ats.count(make_pair(i, j))) {
				gra2[un.getParent(i)].insert(un.getParent(j));
				// cout << i << " " << j << " " << un.getParent(i) << " " << un.getParent(j) << endl;
			}
		}
	}

	int s;
	cin >> s;
	pll te = din(un.getParent(s - 1), -1);
	cout << max(te.x, te.y) << "\n";
	return 0;
}