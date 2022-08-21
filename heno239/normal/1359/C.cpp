#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
#include<chrono>
using namespace std;

//#define int long long
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
typedef pair<ll, ll> LP;

LP calc_dif(LP a, LP b) {
	if (a.first*b.second < a.second*b.first) {
		swap(a, b);
	}
	return { a.first*b.second - a.second*b.first,a.second*b.second };
}

bool great(LP a, LP b) {
	return a.first*b.second < a.second*b.first;
}
void solve() {
	int t, h, c; cin >> h >> c >> t;
	h -= c;
	t -= c;
	LP p = { t,h };
	int ans = 2;
	LP dif = calc_dif({ 1,2 }, p);
	int le = -1, ri = 2000000;
	while (ri - le > 1) {
		int mid = (le + ri) / 2;
		LP pro = { mid + 1,2 * mid + 1 };

		
		if (great(p, pro)) {
			le = mid;
		}
		else {
			ri = mid;
		}

		continue;
		//update
		/*LP d = calc_dif(pro, p);

		LP d2 = d; d2.second /= h;
		LP dif2 = dif; dif2.second /= h;
		if (great(d2, dif2)) {
			ans = 2 * mid + 1;
			dif = d;
		}*/
	}

	for (int i = le - 10; i <= ri + 10; i++) {
		if (i >= 0) {
			LP pro = { i + 1,2 * i + 1 };
			LP d = calc_dif(pro, p);
			LP d2 = d; d2.second /= h;
			LP dif2 = dif; dif2.second /= h;
			if (great(d2, dif2)) {
				ans = 2 * i + 1;
				dif = d;
			}
		}
	}
	cout << ans << "\n";
}



signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t; rep(i, t)
		solve();
		return 0;
}