#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 5, M = 5e5 + 10;
int n, a[N], cnt[N];
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	for(cin >> T; T; T --) {
		cin >> n;
		for(int i = 1; i <= n; i ++) cin >> a[i];
		vector<int> vec;
		map<int, int> s;
		for(int i = 1; i < n; i ++) {
			int d = a[i + 1] - a[i];
			s[d] ++;
		}
		for(int i = 1; i < n - 1; i ++) {
			map<int, int> t;
			int lst = -1;
			for(auto [x, c]: s) {
				if(c > 1) t[0] += c - 1;
				if(lst != -1) t[x - lst] ++;
				lst = x;
			}
			s = t;
		}
		cout << s.begin() -> first << '\n';
	}
	return 0;
}