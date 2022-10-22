#include <bits/stdc++.h>
#define ST first
#define ND second
#define PB push_back

using namespace std;
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 200 * 1000 + 10;
int n, t;
ll a[nax];
ll g[nax][19];

void test_case() {
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for(int i = 1; i < n; ++i) {
		a[i] = abs(a[i] - a[i + 1]);
		g[i][0] = a[i];
	}
	g[n][0] = 1;
	for(int s = 1; s < 19; ++s) {
		for(int i = 1; i < n; ++i) {
			g[i][s] = __gcd(g[i][s - 1], g[min(n - 1, i + (1 << (s - 1)))][s -1]);
		}
		g[n][s] = 1;
	}
	int ans = 0;
	for(int i = 1; i < n; ++i) {
		ll f = 0;
		int x = i;
		for(int s = 18; s >= 0; --s) {
			if(__gcd(f, g[x][s]) > 1) {
				f = __gcd(f, g[x][s]);
				x += (1 << (s));
				x = min(x, n);
			}
		}
		//cout << i << " " << x << "\n";
		ans = max(ans, x - i);
	}
	cout << ans + 1<< "\n";
}
	

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		test_case();
	}
}