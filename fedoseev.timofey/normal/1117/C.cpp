#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef long long ll;
typedef long double ld;

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int n;
    cin >> n;
    string s;
    cin >> s;
	int dx = 0, dy = 0;
	for (int i = 0; i < n; ++i) {
	 	if (s[i] == 'U') ++dy;
	 	if (s[i] == 'D') --dy;
	 	if (s[i] == 'R') ++dx;
	 	if (s[i] == 'L') --dx;
	}
	int l = 0, r = 1e15;
	while (r - l > 1) {
		int m = (l + r) >> 1;
		int cnt = m / n;
		int ddx = cnt * dx;
		int ddy = cnt * dy;
		for (int i = 0; i < m % n; ++i) {
	 		if (s[i] == 'U') ++ddy;
	 		if (s[i] == 'D') --ddy;
	 		if (s[i] == 'R') ++ddx;
	 		if (s[i] == 'L') --ddx;
		}
		if (abs(x2 - (x1 + ddx)) + abs(y2 - (y1 + ddy)) <= m) r = m;
		else l = m;	
	}
	if (r > 1e14) {
	 	cout << "-1\n";
	 	exit(0);
	}
	cout << r << '\n';
}