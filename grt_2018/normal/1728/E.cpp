//GRT_2018
#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 300 * 1000 + 10;
int n;
ll dx[nax];
ll sum;

int ext_gcd(int a, int b, ll &x_0, ll &y_0) {
	if(a == 0) {
		x_0 = 0;
		y_0 = 1;
		return b;
	}
	ll x1, y1;
	int g = ext_gcd(b % a, a, x1, y1);
	// b % a = b - (b/a) * a
	// x1 * (b - (b/a) * a) + a * y1 = g
	y_0 = x1;
	x_0 = y1 - (b/a) * x1;
	return g;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int a, b, i = 1; i <= n; ++i) {
		cin >> a >> b;
		sum += a;
		dx[i] = -a + b;
	}
	sort(dx + 1, dx + n + 1);
	reverse(dx + 1, dx + n + 1);
	int opt = 0;
	for(int i = 1; i <= n; ++i) {
		if(dx[i] > 0) opt = i;
		dx[i] += dx[i - 1];
	}
	int m;
	cin >> m;
	while(m--) {
		ll x, y;
		cin >> x >> y;
		ll x_0, y_0;
		int g = ext_gcd(x, y, x_0, y_0);
		if(n % g != 0) {
			cout << "-1\n";
			continue;
		}
		x_0 *= n/g;
		y_0 *= n/g;
		// x * (x_0 - y/g) + y * (y_0 + x/g) = N
		// x * X + y * Y = n, X >= 0 and Y >= 0
		// y * Y must be as close to opt, as possible
		// (y_0 + x/g* k) = opt/y
		ll k = ((ll)g * opt - (ll)g * y_0 * y) / ((ll)x * y);
		ll ans = -1;
		for(ll kp = k - 5; kp <= k + 5; ++kp) {
			int Y = (y_0 + x/g * kp);
			int X = (n - y * Y) / x;
			if(X < 0 || Y < 0) {
				continue;
			}
			if(x * X + y * Y != n) continue;
			ans = max(ans, sum + dx[y * Y]);
		}
		cout << ans << "\n";
	}
}