#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define ldouble long double
#define nl '\n'
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int radius, width;
	int n, x, y, r;
	cin >> radius >> width;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> r;
		ldouble d = sqrt(x*x+y*y);
		if (d-r >= radius-width && d+r <= radius)
			ans++;
	}
	cout << ans << nl;

	return 0;
}