#include <bits/stdc++.h>
using namespace std;
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	for(cin >> T; T; T --) {
		int n;
		string str;
		cin >> n >> str;
		int m = 2 * n;
		int cur = 0, flag = 1;
		vector<int> pre(m), suf(m);
		int flag1 = -2, flag2 = -2;
		for(int i = 0; i < m; i ++) {
			if(cur < 0) {
				flag2 = i + 1;
				// cout << i << '\n';
			}
			suf[i] = cur;
			if(str[i] == '(') cur ++;
			else cur --;
			flag &= cur >= 0;
			pre[i] = cur;
			if(cur < 0) {
				if(flag1 == -2) flag1 = i - 1;
			} 
		}
		// cout << flag1 << ' ' << flag2 << '\n';
		if(flag) {
			cout << 0 << '\n';
			continue;
		}
		pair<int, int> ans = {-1, -1};
		auto solve = [&] (auto &self, int l, int r) {
			if(l == r) return ;
			int mid = l + r >> 1;
			self(self, l, mid);
			self(self, mid + 1, r);
			int mx = 0, cur = 0, mn = 0;
			// cout << l <<' ' << r << '\n';
			vector<tuple<int, int, int>> p, q;	
			if(mid <= flag1) p.emplace_back(pre[mid], 0, mid + 1);
			for(int i = mid; i >= l; i --) {
				cur += (str[i] == '(' ? 1 : -1);
				// mn +=  (str[i] == '(' ? 1 : -1);
				mn = min(mn, cur);
				if(i - 1 <= flag1) p.emplace_back(i ? pre[i - 1] : 0, cur - mn, i);
			}
			if(mid + 1 >= flag2) q.emplace_back(0, suf[mid + 1], mid);
			cur = 0, mx = 0;
			for(int i = mid + 1; i <= r; i ++) {
				cur += (str[i] == '(' ? 1 : -1);
				mx = max(mx, cur);// cout << str[i] << ' ';
				if(i + 1 >= flag2) q.emplace_back(mx - cur, i == m - 1 ? 0 : suf[i + 1], i);
			}
			// cout << '\n';
			sort(p.begin(), p.end());
			sort(q.begin(), q.end());
			set<pair<int, int>> s;
			// cout << l <<' ' << r << '\n';
			// for(auto [a, b, c] : p) cout << a << ' ' << b << ' ' << c << '\n';
			// cout << "-------------\n";
			// for(auto [a, b, c] : q) cout << a << ' ' << b << ' ' << c << '\n';
			// cout << "-------------\n";
			// // cout << m << '\n';
			// exit(0);
			// cout << get<0> (p[0]) << ' ' << get<0>(q[0]) << '\n';
			for(int i = 0, j = 0; i < p.size() || j < q.size(); ) {
				// cout << i << ' ' << j << '\n';
				if(i == p.size() || j != q.size() && get<0>(p[i]) >= get<0> (q[j])) {
					// cout << "qaq\n";
					s.insert({get<1>(q[j]), get<2> (q[j])});
					j ++;
				}
				else {
					// cout << "qwq\n";
					auto it = s.lower_bound(make_pair(get<1>(p[i]), 0));
					if(it != s.end() && ans.first == -1) {
						// cout << l <<' '  << mid << ' ' << r << '\n';
						// cout << get<0> (p[i]) << ' '  << get<1>(p[i]) << ' ' << get<2>(p[i]) << '\n';
						// cout << it ->first << ' ' << it -> second << '\n';
						ans.first = get<2>(p[i]);
						ans.second = it ->second;
						// cout << ans.first << ' ' << ans.second << '\n';
						// exit(0);
					}
					i ++;
				}
			}
		};
		solve(solve, 0, m - 1);
		if(ans != pair<int, int> {-1, -1}) {
			cout << 1 << '\n';
			cout << ans.first + 1 << ' ' << ans.second + 1 << '\n';
		}
		else {
			int p = max_element(pre.begin(), pre.end()) - pre.begin();
			int q = find(pre.begin(), pre.end(), pre[p]) - pre.begin();
			// cout << pre[p] << '\n';
			cout << 2 << '\n';
			cout << 1 << ' ' << q + 1 << '\n';
			cout << q + 2 << ' ' << m << '\n';
		}
	}
	return 0;
}