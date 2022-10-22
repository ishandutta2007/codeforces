#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <long long, long long> pll;
typedef pair <pll, pii> ppp;

struct DSU {
	int fa[10000010];
	void init(int n) {
		for (int i = 0; i < 10000000; i++) {
			fa[i] = i;
		}
	}
	int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
	void merge(int x, int y) {fa[find(x)] = find(y);}
}dsu;

char buf[10];
set <long long> all;
int OP[50010];
long long X[50010], Y[50010];
vector <ppp> rng;
map <pll, int> input;
int ans[50010];
vector <pii> mdy[50010];
map <pll, int> ID;
int TOT;

int GetId(long long x) {return (--ID.lower_bound(mp(x + 1, 0)))->se;}

void Solve(long long l, long long r, vector <ppp> &L) {
	if (!L.size() || L.size() == 1 && L.back().fi.fi >= l && L.back().fi.se <= r) {
		if (L.size()) L.back().se.se = TOT++;
		return ;
	}
	long long mid = l + r >> 1;
	vector <ppp> R;
	while (L.size() && L.back().fi.fi > mid) R.push_back(L.back()), L.pop_back();
	if (L.size() && L.back().fi.se > mid) R.push_back(L.back()), R.back().fi.fi = mid + 1, L.back().fi.se = mid;
	reverse(R.begin(), R.end());
	Solve(l, mid, L), Solve(mid + 1, r, R);
	int j = 0;
	for (int i = 0; i < L.size(); i++) {
		while (j < R.size() && R[j].fi.se - mid - 1 < L[i].fi.fi - l) j++;
		while (j < R.size() && R[j].fi.fi - mid - 1 <= L[i].fi.se - l) {
			mdy[min(L[i].se.fi, R[j].se.fi)].push_back(mp(L[i].se.se, R[j].se.se));
			j++;
		}
		j = max(j - 1, 0);
	}
	for (auto it : R) {
		L.push_back(it);
	}
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	all.insert(0), all.insert(1ll << n);
	for (int i = 0; i < m; i++) {
		long long x, y; scanf("%s%lld%lld", buf, &x, &y);
		OP[i] = buf[0] == 'b', X[i] = x, Y[i] = y + OP[i];
		if (buf[0] == 'b') all.insert(x), all.insert(y + 1), input[mp(x, y + 1)] = i;
	}
	for (auto it = all.begin(); ; ) {
		auto jt = it; jt++;
		if (jt == all.end()) break;
		rng.push_back(mp(mp(*it, *jt), mp(m, 0)));
		if (input.count(rng.back().fi)) rng.back().se.fi = input[rng.back().fi];
		it = jt;
	}
	sort(rng.begin(), rng.end());
	for (auto &it : rng) {
		it.fi.se--;
	}
	Solve(0, (1ll << n) - 1, rng);
	for (auto &it : rng) {
		ID[it.fi] = it.se.se;
	}
	dsu.init(all.size() - 1);
	for (int i = m; i >= 0; i--) {
		for (auto it : mdy[i]) {
			dsu.merge(it.fi, it.se);
		}
		if (!OP[i]) ans[i] = dsu.find(GetId(X[i])) == dsu.find(GetId(Y[i]));
	}
	for (int i = 0; i < m; i++) {
		if (!OP[i]) printf("%d\n", ans[i]);
	}
	return 0;
}