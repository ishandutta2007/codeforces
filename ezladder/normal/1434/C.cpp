#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

ll a, b, c, d;

ll MAXF = 1e18;

ll mult(ll a, ll b) {
	if (b == 0) return 0 ;
	ll can = MAXF / b;
	if (a < can) return a * b;
	return MAXF;
}

void solve() {
	cin >> a >> b >> c >> d;
	a += b;
	c++;
	if (b * c < a) { cout << "-1\n"; return; }
	if (c < d) {
		cout << a - b << "\n";
		return;
	}
	ll min_k = 1;
	ll max_k = (c - 1) / d + 1;
	ll pos = a / (b * d);
	ll ans = -a + b;



	for (ll k = max(min_k, pos - 5); k <= min(max_k, pos + 5); ++k) {
		ans = min(ans, -k * a + b * k + mult(k * (k - 1) / 2, b * d)); // CHECK
		//cout << k << ' ' << -k * a + b * k + mult(k * (k - 1) / 2, b * d) << endl;
	}
	for (ll k = min_k; k <= min(max_k, min_k + 5); ++k) {
		ans = min(ans, -k * a + b * k + mult(k * (k - 1) / 2, b * d)); // CHECK
	}
	for (ll k = max(min_k, max_k - 5); k <= max_k; ++k) {
		ans = min(ans, -k * a + b * k + mult(k * (k - 1) / 2, b * d)); // CHECK
	}

//	cout << c << ' ' << d << ' ' << ans << endl;
 
	ll cnt = max_k;
	if (c - 1 > d * (cnt - 1)) {
		ll delta2 = d - (c - 1 - d * (cnt - 1));
		ll delta1 = d - delta2;
	//	cout << c - 1 << ' ' << d * (cnt - 1) << endl;
	//	cout << delta1 << ' ' << delta2 << endl;
		ll now = -cnt * a + b * cnt + mult(cnt * (cnt - 1) / 2, b * d);
	//	cout << now << endl;
	//	cout << now << ' ' << delta1 << ' ' << delta2 << ' ' << cnt << endl;
		now += mult(mult(cnt, delta1), b);
		now += mult(mult(cnt - 1, delta2), b);
		now -= a - b;
		ans = min(ans, now);
	}


	cout << -ans << '\n';
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}

}