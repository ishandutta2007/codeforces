#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int b, p, f, h, c; cin >> b >> p >> f >> h >> c;
		b /= 2;
		if (h < c) swap(h,c), swap(p, f);
		cout << min(b, p) * h + (min(b, p+f) - min(b,p)) * c << '\n';
	}


	return 0;
}