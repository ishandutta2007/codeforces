#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, m, cl, ce, v;
	cin >> n >> m >> cl >> ce >> v;

	int stair[cl], magic[ce];
	for (int i = 0; i < cl; i++) {
		cin >> stair[i];
	}
	for (int i = 0; i < ce; i++) {
		cin >> magic[i];
	}
	sort(stair, stair+cl);
	sort(magic, magic+ce);

	int q;
	cin >> q;

	int a, b, x, y;
	for (int i = 0; i < q; i++) {
		cin >> a >> b >> x >> y;
		int ans = INF;
		if (a == x) {
			ans = abs(b-y);
		} else {
			int* it;
			// stairs
			it = lower_bound(stair, stair+cl, b);
			if (it != stair+cl) {
				ans = min(ans, abs(a-x) + abs(*it-b) + abs(*it-y));
			}
			if (it != stair) {
				--it;
				ans = min(ans, abs(a-x) + abs(*it-b) + abs(*it-y));
			}
			it = lower_bound(stair, stair+cl, y);
			if (it != stair+cl) {
				ans = min(ans, abs(a-x) + abs(*it-b) + abs(*it-y));
			}
			if (it != stair) {
				--it;
				ans = min(ans, abs(a-x) + abs(*it-b) + abs(*it-y));
			}
			// elevators
			it = lower_bound(magic, magic+ce, b);
			if (it != magic+ce) {
				ans = min(ans, (abs(a-x)+v-1)/v + abs(*it-b) + abs(*it-y));
			}
			if (it != magic) {
				--it;
				ans = min(ans, (abs(a-x)+v-1)/v + abs(*it-b) + abs(*it-y));
			}
			it = lower_bound(magic, magic+ce, y);
			if (it != magic+ce) {
				ans = min(ans, (abs(a-x)+v-1)/v + abs(*it-b) + abs(*it-y));
			}
			if (it != magic) {
				--it;
				ans = min(ans, (abs(a-x)+v-1)/v + abs(*it-b) + abs(*it-y));
			}
		}
		cout << ans << nl;
	}

	return 0;
}