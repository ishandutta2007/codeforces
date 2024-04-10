#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<i64> a(n);
	for(int i = 0; i < n; i ++) cin >> a[i];
	vector<i64> ans(2);
	vector<i64> rev(2 * m + 1);
	for(int s = 2; s <= 2 * m; s ++) {
		vector<int> pos;
		auto ins = [&] (int l, int r) {
			if(l <= r) {
				if(l != 1)	pos.emplace_back(l);
				pos.emplace_back(r + 1);
			}
		};
		for(auto u : a) {
			u %= s;
			ins(1, min(s - u - 1, u));
			ins(max(s - u, u / 2 + 1), s / 2);
			ins(s - u, u / 2);
		}
		pos.emplace_back(1);
		sort(pos.begin(), pos.end());
		pos.erase(unique(pos.begin(), pos.end()), pos.end());
		for(int i = 0; i < pos.size(); i ++) rev[pos[i]] = i;
		vector<vector<int>> cnt(pos.size(), vector<int> (3));
		auto add = [&] (int type, int l, int r) {
			if(l <= r) {
				l = rev[l];
				r = rev[r + 1];
				// l = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
				// r = lower_bound(pos.begin(), pos.end(), r + 1) - pos.begin();
				cnt[l][type] ++;
				cnt[r][type] --;
			}
		};
		for(auto u : a) {
			u %= s;
			add(0, 1, min(s - u - 1, u));
			add(1, max(s - u, u / 2 + 1), s / 2);
			add(2, s - u, u / 2);
		}
		while(!pos.empty() && pos.back() >= (s + 1) / 2) pos.pop_back(); 
		pos.emplace_back((s + 1) / 2);
		for(int i = 0; i < pos.size() - 1; i ++) {
			if(i) for(int j = 0; j < 3; j ++) {
				cnt[i][j] += cnt[i - 1][j];
			}
			if(s - m >= pos[i + 1]) continue;
			int len = pos[i + 1] - max(pos[i], s - m);
			if(!cnt[i][0]) {
				if(!cnt[i][2]) {
					ans[cnt[i][1] & 1] += 2 * len;
				}
				else if(cnt[i][2] == 1) {
					if(1 + cnt[i][1] & 1) ans[1] += 2 * len;
				}
			}
		}
	}
	for(int i = 1; i <= m; i ++) {
		i64 ret = 0;
		for(auto u : a) ret += u / i;
		ans[ret & 1] ++;
	}
	i64 s = 1ll * m * m - ans[0] - ans[1];
	cout << s / 2 << ' ' << s / 2 << ' ' << ans[1] << ' ' << ans[0] << '\n';
	return 0;
}