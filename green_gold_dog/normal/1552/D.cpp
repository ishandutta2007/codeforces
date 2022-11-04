#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		ll n;
		cin >> n;
		bool bm = false;
		vector<ll> arr(n, 0);
		for (ll i = 0; i < n; i++) {
			cin >> arr[i];
		}
		for (ll i = 0; i < n; i++) {
			set<ll> s;
			s.insert(0);
			for (ll j = 0; j < n; j++) {
				if (j != i) {
					set<ll> os = s;
					for (auto& k : os) {
						s.insert(k-arr[j]);
					}
				}
			}
			for (auto& j : s) {
				if (s.find(j-arr[i]) != s.end()) {
					bm = true;
				}
			}
		}
		cout << (bm ? "YES" : "NO") << '\n';
	}
}