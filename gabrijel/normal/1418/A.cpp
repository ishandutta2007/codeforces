#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	REP(tt, t) {
		ll x, y, k;
		cin >> x >> y >> k;
		y *= k;
		y += k;
		ll n = (y - 1 + x - 2) / (x - 1);
		n += k;
		cout << n << "\n";
	}
	return 0;
}