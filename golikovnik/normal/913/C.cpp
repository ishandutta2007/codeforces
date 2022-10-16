#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).end()
#define sz(x) (int) x.size()
#define X first
#define Y second
#define endl '\n'

typedef long long ll;
typedef long double ld;
typedef double D;

template<class T = int> inline T read() {
	T x;
	cin >> x;
	return x;
}
template<class T> void uax(T &a, T b) {return a > b ? (a = b, true) : false;}
template<class T> void uin(T &a, T b) {return a < b ? (a = b, true) : false;}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout << fixed;
	int n = read();
	ll L = read<ll>();
	ll Lstart = L;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i) a[i] = read();
	vector<ll> dp(n);
	dp[0] = a[0];
	for (int i = 1; i < n; ++i) {
		dp[i] = min(a[i], dp[i - 1] * 2);
	}
	for (int i = n - 1; i > 0; --i) {
		dp[i-1] = min(dp[i-1], dp[i]);
	}
	ll ans = LLONG_MAX;
	ll res = 0;
	for (int i = n - 1; i >= 0; --i) {
		for (int i = n - 1; i >= 0; --i) {
			int w = 1ll << i;
			int take = (L + w - 1) / w;
			ans = min(ans, take * dp[i] + res);
		}
		if (L <= 0ll) break;
		int w = 1ll << i;
		int take = L / w;
		L -= take * w;
		res += take * dp[i];
	}
	for (int i = n - 1; i >= 0; --i) {
		int w = 1ll << i;
		int take = (L + w - 1) / w;
		ans = min(ans, take * dp[i] + res);
	}
	ans = min(ans, res);
	cout << ans << endl;
	return 0;
}