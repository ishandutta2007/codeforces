#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll a, b,c,d,e,f; cin >> a >> b >> c >> d >> e >> f;
	b = min(b,c);
	a = min(a,d);
	b = min(b,d);
	if (a+b > d) {
		if (e > f) b = d-a;
		else a = d-b;
	}
	cout << a * e + b * f << '\n';

	return 0;
}