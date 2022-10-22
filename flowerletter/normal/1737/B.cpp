#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false), cin.tie(0);
	int T;
	for(cin >> T; T; T --) {
		i64 l, r;
		cin >> l >> r;
		auto solve = [&] (i64 x) {
			i64 t = sqrt(x) + 10, ans = 0;
			while(t * t > x) t --;
			ans += t;
			while(t * (t + 1) > x) t --;
			ans += t;
			while(t * (t + 2) > x) t --;
			ans += t;
			return ans;
		};
		// cout << l << ' ' << r << '\n';
		cout << solve(r) - solve(l - 1) << '\n';
	}
	return 0;
}