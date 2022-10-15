#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		string s;
		cin >> n >> s;
		int lg = (int) log2(n);
		function<int(int, int, char)> dq = [&](int l, int r, char cur) -> int {
			if (l == r) {
				return (s[l - 1] != cur);
			}
			int sz = (r - l + 1) >> 1;
			int ans = 0;
			for (int i = l - 1; i < l + sz - 1; ++i) {
				ans += s[i] != cur;				
			}
			ans += dq(l + sz, r, cur + 1);
			int ans2 = 0;
			for (int i = l + sz - 1; i < r; ++i) ans2 += s[i] != cur;
			ans2 += dq(l, r - sz, cur + 1);
			ans = min(ans, ans2);				 			
			return ans;
		};
		cout << dq(1, n, 'a') << '\n';
	}
}