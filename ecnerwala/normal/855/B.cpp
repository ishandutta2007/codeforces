#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	ll P, Q, R;
	int N;
	cin >> N >> P >> Q >> R;
	ll d1, d2, d3;
	cin >> d1;
	d3 = (P + Q + R) * d1;
	d2 = (P + Q) * d1;
	d1 = P * d1;

	for (int i = 1; i < N; i++) {
		ll v; cin >> v;
		d1 = max(d1, P * v);
		d2 = max(d2, d1 + Q * v);
		d3 = max(d3, d2 + R * v);
	}

	cout << d3 << '\n';

	return 0;
}