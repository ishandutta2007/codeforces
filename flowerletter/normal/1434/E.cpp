#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10, B = 450;
int n, v[N], pos[N], f[N], use[B];
int g[N][B];
struct dsu_t {
	int fa[N];
	void init(int n) {iota(fa, fa + n + 1, 0);}
	int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
	auto calc(int l, int r) {
		vector<int> vec;
		for(int i = find(l); i <= r; i = find(i)) {
			vec.emplace_back(i);
			fa[i] = i + 1;
		}
		return vec;
	}
}dsu[B];
int solve() {
	cin >> n;
	memset(use, 0, sizeof(use));
	memset(f, 0, sizeof(f));
	memset(pos, 0, sizeof(pos));
	for(int i = 1; i < n; i ++) {
		memset(g[i], 0, B << 2);
	}
	for(int i = 1; i <= n; i ++) {
		cin >> v[i];
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = v[i - 1] + 1; j <= v[i]; j ++) pos[j] = i;
	}
	auto get = [&] (int l, int r) {
		int w = v[r] - v[l], x = v[l] - w;
		return x <= 0 ? 1 : pos[x + 1];
	};
	for(int i = 1; i < n; i ++) f[i] = 1, g[i][1] = n;
	for(int i = 0; i < B; i ++) use[i] = 0, dsu[i].init(n + 1);
	use[0] = 1;
	for(int i = n - 1; i >= 1; i --) {
		int lst = i + 1, nxt = i - 1;
		for(int x = B - 1; x >= 0; x --) if(g[i][x]) {
			if(lst == i + 1) use[x] = 1;
			int r = g[i][x], l = lst;
			assert(i < l && l <= r);
			int pl = get(i, r), pr = nxt; nxt = pl - 1;
			assert(pr < i);
			auto vec = dsu[x].calc(pl, pr);
			for(auto j : vec) {
				if(g[j][f[j]] == i) g[j][f[j]] = 0;
				while(dsu[f[j]].find(j) > j) f[j] ++;
				if(!g[j][f[j]]) {
					g[j][f[j]] = i;
				}
			}
			lst = g[i][x] + 1;
		}
		assert(lst == n + 1);
	}
	int mex = 0;
	while(use[mex]) mex ++;
	return mex;
}

int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T, sum = 0;
	for(cin >> T; T; T --) {
		sum ^= solve();
	}
	cout << (sum ? "YES\n" : "NO\n");
	return 0;
}