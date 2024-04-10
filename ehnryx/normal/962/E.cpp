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

	int n;
	cin >> n;

	int a;
	char c;
	vector<int> red, green, blue;
	for (int i = 0; i < n; i++) {
		cin >> a >> c;
		if (c == 'R') red.push_back(a);
		else if (c == 'B') blue.push_back(a);
		else green.push_back(a);
	}

	ll ans = 0;
	if (green.empty()) {
		if (!red.empty()) ans += red.back() - red.front();
		if (!blue.empty()) ans += blue.back() - blue.front();
	}
	else {
		// first part
		if (!red.empty() && red.front() < green.front()) ans += green.front() - red.front();
		if (!blue.empty() && blue.front() < green.front()) ans += green.front() - blue.front();

		// middle part
		for (int i = 1; i < green.size(); i++) {
			vector<int>::iterator cur_red = lower_bound(red.begin(), red.end(), green[i-1]);
			vector<int>::iterator last_red = upper_bound(red.begin(), red.end(), green[i]);
			vector<int>::iterator cur_blue = lower_bound(blue.begin(), blue.end(), green[i-1]);
			vector<int>::iterator last_blue = upper_bound(blue.begin(), blue.end(), green[i]);

			int prev_red, prev_blue, res_red, res_blue;
			prev_red = prev_blue = green[i-1];
			res_red = res_blue = -INF;

			while (cur_red != last_red) {
				res_red = max(res_red, *cur_red - prev_red);
				prev_red = *cur_red;
				cur_red++;
			}
			res_red = max(res_red, green[i] - prev_red);

			while (cur_blue != last_blue) {
				res_blue = max(res_blue, *cur_blue - prev_blue);
				prev_blue = *cur_blue;
				cur_blue++;
			}
			res_blue = max(res_blue, green[i] - prev_blue);

			int len = green[i] - green[i-1];
			ans += min((ll)2*len, (ll)3*len - res_red - res_blue);
		}

		// last part
		if (!red.empty() && red.back() > green.back()) ans += red.back() - green.back();
		if (!blue.empty() && blue.back() > green.back()) ans += blue.back() - green.back();
	}

	cout << ans << nl;

	return 0;
}