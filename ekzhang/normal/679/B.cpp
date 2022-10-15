#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

LL cbrt(LL x) {
	// floor of cube root
	LL lo = 0;
	LL hi = 2e5;
	while (lo != hi) {
		LL mid = (lo + hi + 1) / 2;
		if (mid * mid * mid <= x) {
			lo = mid;
		}
		else {
			hi = mid - 1;
		}
	}
	return lo;
}

pair<LL, LL> go(LL m) {
	if (m < 8) {
		return { m, m };
	}
	LL k = cbrt(m);
	LL b = k * k * k;
	LL a = (k - 1) * (k - 1) * (k - 1);
	
	auto ansb = go(m - b);
	ansb.first += 1;
	ansb.second += b;

	auto ansa = go(b - a - 1);
	ansa.first += 1;
	ansa.second += a;

	return max(ansa, ansb);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	LL M;
	cin >> M;
	auto ans = go(M);

	cout << ans.first << ' ' << ans.second << endl;
	return 0;
}