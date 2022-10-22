#include <bits/stdc++.h>
using namespace std;
int main() {
// 	freopen("in.txt", "r", stdin);
	int T;
	for(cin >> T; T; T --) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		string str;
		cin >> str;
		int n = str.size();
		int cnta = count(str.begin(), str.end(), 'A');
		int cntb = count(str.begin(), str.end(), 'B');
		if(cnta != a + c + d || cntb != b + c + d) {
			cout << "NO\n";
			continue;
		}
		vector<int> len[2];
		string cur; cur += str[0];
		int all = 0;
		for(int i = 1; i <= n; i ++) {
			if(i == n || str[i] == str[i - 1]) {
				// cout << cur << '\n';
				if(cur.size() & 1) {
					all += cur.size() / 2;
				}
				else {
					len[cur[0] - 'A'].push_back(cur.size() / 2);
				}
				cur.clear();
			}
			if(i < n) cur += str[i];
		}
		sort(len[0].begin(), len[0].end());
		sort(len[1].begin(), len[1].end());
		reverse(len[1].begin(), len[1].end());
		// cout << all << '\n';
		// for(auto u : len[0]) cout << u << ' '; cout << '\n';
		// for(auto u : len[1]) cout << u << ' '; cout << '\n';
		for(auto &u : len[0]) {
			int t = min(c, u);
			c -= t;
			u -= t;
		}
		int t = min(all, c);
		all -= t;
		c -= t;
		// cout << all << ' ' << c << '\n';
		if(c) {
			for(auto &u : len[1]) {
				u --;
				int t = min(c, u);
				c -= t;
				u -= t;
				if(!c) break;
			}
			if(c) {
				cout << "NO\n";
				continue;
			}
		}
		t = min(all, d);
		all -= t, d -= t;
		for(auto &u : len[0]) if(u) {
			u --;
			int t = min(d, u);
			d -= t;
			u -= t;
		}
		for(auto &u : len[1]) {
			int t = min(d, u);
			d -= t;
			u -= t;
		}
		if(d) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}