#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, k;
	cin >> n >> k;
	multiset<ll> s;
	for (ll i = 0; i < k; i++) {
		s.insert(0);
	}
	for (ll i = 0; i < n; i++) {
		ll t, m;
		cin >> t >> m;
		cout << max(t, *s.begin())+m << '\n';
		s.insert(max(t, *s.begin())+m);
		s.erase(s.begin());
	}
}