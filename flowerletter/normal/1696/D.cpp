#include <bits/stdc++.h>
using namespace std;
constexpr int N = 3e5 + 10, M = 19, inf = 1e9;
int a[N];
pair<int, int> mn[M][N], mx[M][N];
int f[N], g[N];
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	for(cin >> T; T; T --) {
		int n;
		cin >> n;
		for(int i = 1; i <= n; i ++) cin >> a[i], mn[0][i] = mx[0][i] = {a[i], i}, f[i] = g[i] = n + 1;
		int m = __lg(n) + 1;
		for(int i = 1; i < m; i ++) {
			for(int j = 1; j <= n - (1 << i) + 1; j ++) {
				mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1 << i - 1)]);
				mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << i - 1)]);
			}
		}
		// cout << "qwq\n";
		auto qrymx = [&] (int l, int r) {
			int k = __lg(r - l + 1);
			return max(mx[k][l], mx[k][r - (1 << k) + 1]).second;
		};
		auto qrymn = [&] (int l, int r) {
			int k = __lg(r - l + 1);
			return min(mn[k][l], mn[k][r - (1 << k) + 1]).second;
		};
		vector<int> stk;
		for(int i = 1; i <= n; i ++) {
			while(!stk.empty() && a[stk.back()] < a[i]) f[stk.back()] = i, stk.pop_back();
			stk.emplace_back(i);
		}
		stk.clear();
		for(int i = 1; i <= n; i ++) {
			while(!stk.empty() && a[stk.back()] > a[i]) g[stk.back()] = i, stk.pop_back();
			stk.emplace_back(i);
		}
		stk.clear();
		int cur = 0, p = 1;
		while(p < n) {
			cur ++;
			// cout << p << '\n';
			// if(!p) break;
			if(a[p] < a[p + 1]) {
				int q = g[p] - 1;
				p = qrymx(p, q);
			}
			else {
				int q = f[p] - 1;
				p = qrymn(p, q);
			}
		}
		cout << cur << '\n';
	}
	return 0;
}