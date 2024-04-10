#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

const ll INF = 1e8;

using namespace std;

ll gcd(ll a, ll b) {
	if (a % b) return gcd(b, a % b);
	return b;
}

ll solve(vector <ll> p, ll a, ll b, ll x, ll y, ll need, int n) {
	vector <ll> arr(n);
	int it = 0;
	ll k = (a * b) / gcd(a, b);
	for (int i = k - 1; i < n; i += k)
		arr[i] = p[it++];
	for (int i = a - 1; i < n; i += a)
		if (!arr[i])
			arr[i] = p[it++];
	for (int i = b - 1; i < n; i += b)
		if (!arr[i])
			arr[i] = p[it++];
	ll ans = 0, cnt = INF;
	for (int i = 0; i < n; i++) {
		if (i % a == a - 1)
			ans += arr[i] * x;
		if (i % b == b - 1)
			ans += arr[i] * y;
		if (ans >= need) {
			cnt = i + 1;
			break;
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector <ll> p(n);
		for (int i = 0; i < n; i++)
			cin >> p[i];
		sort(p.rbegin(), p.rend());
		ll x, a;
		cin >> x >> a;
		ll y, b;
		cin >> y >> b;
		if (y > x) {
			swap(x, y);
			swap(a, b);
		}
		ll k;
		cin >> k;
		k *= 100;
		int L = 1;
		int R = n + 1;
		while (L != R) {
			int M = (L + R) / 2;
			ll ans = solve(p, a, b, x, y, k, M);
			if (ans == INF) L = M + 1;
			else R = M;
		}
		if (L == n + 1) cout << -1 << '\n';
		else cout << L << '\n';
	}
	return 0;
}