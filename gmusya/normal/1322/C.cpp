#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'
#define ll long long

using namespace std;

const ll MOD1 = 10000000007;
const ll MOD2 = 655360001;
const ll P = 614657;

struct vertex {
	ll siz, val;
	ll hash1, hash2;
};

bool cmp(vertex a, vertex b) {
	return (a.siz < b.siz) || (a.siz == b.siz && a.hash1 < b.hash1) || (a.siz == b.siz && a.hash1 == b.hash1 && a.hash2 < b.hash2);
}

ll gcd(ll a, ll b) {
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		ll n, m;
		cin >> n >> m;
		vector <ll> a(n);
		for (ll i = 0; i < n; i++)
			cin >> a[i];
		vector <vector <ll>> g(n);
		for (ll i = 0; i < m; i++) {
			ll u, v;
			cin >> u >> v;
			v--;
			g[v].push_back(u);
		}
		vector <vertex> k(n);
		for (ll i = 0; i < n; i++) {
			sort(g[i].begin(), g[i].end());
			k[i].siz = g[i].size();
			k[i].val = a[i];
			for (ll x : g[i]) {
				k[i].hash1 = ((k[i].hash1 * P) + x) % MOD1;
				k[i].hash2 = ((k[i].hash2 * P) + x) % MOD2;
			}
		}
		sort(k.begin(), k.end(), cmp);
		vector <ll> b;
		ll sum = 0;
		for (ll i = 0; i < n; i++) {
			if (k[i].siz == 0)
				continue;
			if (i != 0 && (k[i].siz != k[i - 1].siz || k[i].hash1 != k[i - 1].hash1 || k[i].hash2 != k[i].hash2)) {
				if (sum != 0) b.push_back(sum);
				sum = 0;
			}
			sum += k[i].val;
		}
		b.push_back(sum);
		ll ans = 0;
		for (ll i = 0; i < b.size(); i++) 
			ans = gcd(ans, b[i]);
		cout << ans << endl;
	}
	return 0;
}