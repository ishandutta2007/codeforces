#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	ll tx = 0, ty = 0;
	for (int i = 0; i < 2 * N; i++) {
		ll x, y; cin >> x >> y;
		tx += x, ty += y;
	}
	cout << (tx / N) << ' ' << (ty / N) << '\n';
	return 0;
}