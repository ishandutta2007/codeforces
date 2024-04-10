#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
int n, a[N], b[N], mx[N], mn[N];
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	for(cin >> T; T; T --) {
		cin >> n;
		for(int i = 1; i <= n; i ++) cin >> b[i];
		for(int i = 1; i <= n; i ++) mx[i] = max(b[i], mx[i - 1]);
		mn[n + 1] = 1e9;
		for(int i = n; i >= 1; i --) mn[i] = min(mn[i + 1], b[i]);
		// for(int i = 0; i <= n; i ++) if(mx[i] > i && mn[i + 1] <= i) {
		vector<int> ans;
		int k = 0;
		vector<vector<int>> vec(n + 2);
		for(int i = 1; i <= n; i ++) {
			vec[b[i]].emplace_back(i);
			if(b[i] > i) k = max(k, i);
		}
		cout << k << '\n';
		int cur = vec[0].size() ? 0 : n + 1;
		for( ; ; ) {
			int nxt = 0;
			for(auto x : vec[cur]) nxt |= vec[x].size() ? x : 0;
			for(auto x : vec[cur]) if(x != nxt) cout << x << ' ';
			if(!nxt) break;
			cout << nxt << ' ';
			cur = nxt;
		}
		cout << '\n';
	}
	return 0;
}