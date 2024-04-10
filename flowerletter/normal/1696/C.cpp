#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	for(cin >> T; T; T --) {
		int n, m, k;
		cin >> n >> m;
		auto solve = [&] (vector<int> s) {
			vector<pair<int, i64>> t;
			for(auto x : s) {
				i64 cnt = 1;
				while(x % m == 0) {
					x /= m, cnt *= m;
				}
				if(t.empty() || t.back().first != x) {
					t.emplace_back(x, cnt);
				}
				else {
					t.back().second += cnt;
				}
			}
			return t;
		};
		vector<int> a(n);
		for(int i = 0; i < n; i ++) cin >> a[i];
		cin >> k;
		vector<int> b(k);
		for(int i = 0; i < k; i ++) cin >> b[i];
		cout << (solve(a) == solve(b) ? "YES\n" : "NO\n");
	}
	return 0;
}