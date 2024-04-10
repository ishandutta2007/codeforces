#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size())
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define all(c) (c).begin(), (c).end()
 
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	ll x0, y0, ax, ay, bx, by;
	ll xs, ys, t;
	cin >> x0 >> y0 >> ax >> ay >> bx >> by;
	cin >> xs >> ys >> t;
	vector<pair<ll, ll>> coord;
	while(1) {
		coord.pb(mp(x0, y0));
		x0 = x0 * ax + bx;
		y0 = y0 * ay + by;
		if (x0 - xs + y0 - ys > t) break;
	}
	int n = sz(coord);
	int ans = 0;
	forn(close, n) {
		forn(first, close + 1) {
			forab(last, close, n) {
				ll len = abs(xs - coord[close].fst) + abs(ys - coord[close].snd);
				ll len1 = abs(coord[first].fst - coord[close].fst) + abs(coord[first].snd - coord[close].snd);
				ll len2 = abs(coord[last].fst - coord[close].fst) + abs(coord[last].snd - coord[close].snd);
				if (len + len1 + len2 + min(len1, len2) <= t) {
					ans = max(ans, last - first + 1);
				}
			}
		}
	} 
	cout << ans << '\n';
    return 0;
}