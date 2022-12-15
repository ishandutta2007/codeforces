#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int SIZE = 1005;

ll a[SIZE];
ll b[SIZE];
ll e[SIZE];

int main() {
	int n, k1, k2;
	cin >> n >> k1 >> k2;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	priority_queue<ll> h;
	for(int i = 0; i < n; i++) {
		cin >> b[i];
		h.push(abs(a[i] - b[i]));
	}
	for(int j = 0; j < k1 + k2; j++) {
		ll x = h.top();
		h.pop();
		x = abs(x - 1);
		h.push(x);
	}
	ll ans = 0;
	while(!h.empty()) {
		ll erro = h.top();
		ans += erro * erro;
		h.pop();
	}
	cout << ans << '\n';
	return 0;
}