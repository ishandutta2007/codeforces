#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

vector <int> from[100010];
int dep[100010], fa[100010];
int dw[100010], up[100010];
int dwp[100010], upp[100010];
int path[100010];

int Query(int x) {
	cout << "? " << x << endl;
	int y; cin >> y;
	return y;
}

void GetFa(int x, int last) {
	fa[x] = last; for (auto v : from[x]) if (v != last) GetFa(v, x);
}

void GetDep(int x, int last) {
	for (auto v : from[x]) if (v != last) dep[v] = dep[x] + 1, GetDep(v, x);
}

void GetDw(int x, int last) {
	for (auto v : from[x]) if (v != last) GetDw(v, x);
	vector <int> all;
	for (auto v : from[x]) if (v != last) all.push_back(dw[v]);
	dw[x] = 1;
	if (!all.size()) {
		path[x] = -1;
		return ;
	}
	sort(all.rbegin(), all.rend());
	for (int i = 0; i < all.size(); i++) dw[x] = max(dw[x], all[i] + i);
	for (auto v : from[x]) if (v != last && dw[v] == all[0]) path[x] = v;
}

void GetUp(int x, int last, int val) {
	vector <int> all;
	if (val != -1) all.push_back(val), up[x] = val;
	for (auto v : from[x]) if (v != last) all.push_back(dw[v]);
	sort(all.rbegin(), all.rend());
	vector <int> pre(all.size()), suc(all.size());
	for (int i = 0; i < all.size(); i++) pre[i] = suc[i] = all[i];
	for (int i = 0; i < all.size(); i++) pre[i] += i, suc[i] += i - 1;
	for (int i = 1; i < all.size(); i++) pre[i] = max(pre[i], pre[i - 1]);
	for (int i = (int)all.size() - 2; i >= 0; i--) suc[i] = max(suc[i], suc[i + 1]);
	for (auto v : from[x]) if (v != last) {
		int pos = lower_bound(all.begin(), all.end(), dw[v], greater <int>()) - all.begin();
		GetUp(v, x, max(1, max(pos ? pre[pos - 1] : 0, pos + 1 < all.size() ? suc[pos + 1] : 0)));
	}
}

int GetDp(int x, int last) {
	if (fa[x] == last) return dw[x];
	return up[last];
}

int Solve(int x, int last) {
	int P = x; while (path[P] != -1) P = path[P];
	int val = Query(P);
	if (dep[val] < dep[x]) return -1;
	vector <pii> all;
	if (path[val] == -1) return val;
	for (auto v : from[val]) if (v != fa[val] && v != path[val]) all.push_back(mp(dw[v], v));
	sort(all.rbegin(), all.rend());
	for (auto it : all) {
		int v = it.se;
		int tmp = Solve(v, val);
		if (tmp != -1) return tmp;
	}
	return val;
}

int main() {
	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		from[x].push_back(y);
		from[y].push_back(x);
	}
	GetFa(1, 1), GetDw(1, 1), GetUp(1, 1, -1);
	int ans = 0;
	if (n > 1) {
		for (int i = 1; i <= n; i++) {
			vector <int> all;
			for (auto x : from[i]) all.push_back(GetDp(x, i));
			sort(all.rbegin(), all.rend());
			ans = max(ans, all[0] + (int)all.size() - 1);
			for (int i = 1; i < all.size(); i++) ans = max(ans, all[i] + all[0] + i - 1);
		}
	}
	cout << ans << endl;
	int rt; cin >> rt;
	GetDw(rt, rt), GetDep(rt, rt), GetFa(rt, rt);
	vector <pii> all;
	for (auto x : from[rt]) all.push_back(mp(GetDp(x, rt), x));
	sort(all.rbegin(), all.rend());
	int A = -1, B = -1;
	for (auto it : all) {
		int x = it.se, val = Solve(x, rt);
		if (val != -1) {
			if (A == -1) A = val;
			else B = val;
			if (B != -1) break;
		}
	}
	if (A == -1) A = rt;
	if (B == -1) B = rt;
	cout << "! " << A << " " << B << endl;
	return 0;
}