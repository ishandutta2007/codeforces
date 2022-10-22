#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n;
	cin >> n;
	vector<int> ok(n + 1), fa(n + 1), deg(n + 1), c(n + 1), sz(n + 1, 1), sumdeg(n + 1);
	for(int i = 1; i <= n; i ++) cin >> deg[i], ok[i] = deg[i] <= 1, sumdeg[i] = deg[i];
	iota(fa.begin(), fa.end(), 0);
	function<int(int)> find =[&] (int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);};
	auto ask = [&] (int u) {
		cout << "? "<< u << '\n';
		cout.flush();
		int v; cin >> v;
		return v;
	};
	auto merge = [&] (int u, int v) {
		int x = find(u), y = find(v);
		fa[x] = y;
		sz[y] += sz[x];
		sumdeg[y] += sumdeg[x];
		ok[y] = 1ll * sz[y] * sz[y] >= sumdeg[y];
	};
	vector<int> id(n);
	iota(id.begin(), id.end(), 1);
	sort(id.begin(), id.end(), [&] (int x, int y) {return deg[x] > deg[y];});
	for(int i : id) if(!ok[find(i)]) {
		for(int j = 0; j < deg[i]; j ++) {
			int v = ask(i);
			merge(i, v);
			if(ok[find(i)]) break;
		}
	}
	cout << "!";
	for(int i = 1; i <= n; i ++) cout << ' ' << find(i); cout << endl;
}
int main() {
	ios::sync_with_stdio(false);
	int T;
	for(cin >> T; T; T --) {
		solve();
	}
	return 0;
}