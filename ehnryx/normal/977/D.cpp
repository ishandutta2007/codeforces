#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;

	ll a[n];
	unordered_set<ll> seen;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		seen.insert(a[i]);
	}

	vector<ll> ans;
	for (int i = 0; i < n; i++) {
		ans.clear();
		ll cur = a[i];
		for (;;) {
			ans.push_back(cur);
			if (seen.count(2*cur)) cur *= 2;
			else if (cur%3 == 0 && seen.count(cur/3)) cur /= 3;
			else break;
		}
		if (ans.size() == n) break;
	}

	for (ll it : ans) cout << it << " ";
	cout << nl;


	return 0;
}