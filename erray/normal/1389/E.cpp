#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int m, d, w;
		cin >> m >> d >> w;
		w /= __gcd(d - 1, w);
		cerr << w << ' ';
		// (x - y) % w = 0 x, y <= min(m, d)
		m = min(d, m);
		int cr = m / w, f = m % w;
		cout << 1ll * (cr - 1) * cr / 2 * w + 1ll * f * cr << '\n';	
	}
}