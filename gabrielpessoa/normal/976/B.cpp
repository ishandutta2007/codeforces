#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll n, m, k;
	cin >> n >> m >> k;
	if(k < n) {
		cout << k + 1 << ' ' << 1 << '\n';
	} else {
		k -= n;
		ll moves = (k) / (m - 1);
		cout << n - moves << ' ';
		if(moves % 2 == 0) {
			cout << k % (m - 1) + 2 << '\n';
		} else {
			cout << m - k % (m - 1) << '\n';
		}
	}
}