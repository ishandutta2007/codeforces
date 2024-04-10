#include <bits/stdc++.h> 
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end() 
 
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vi a(n);
		ll s = 0;
		forn(i, n) {
			cin >> a[i];
			s += a[i];
		}
		sort(all(a));
		if (a[0] * 1ll * (n - 2) + s > 0) {
			cout << "INF\n";
			continue;
		}
		if (a.back() * 1ll * (n - 2) + s < 0) {
			cout << "INF\n";
			continue;
		}
	//	cout << "OK\n";
		// t from -INF to INF
		ll coeffT = 0, sum = 0;
		ll best = -1e18;
		forn(i, n - 1) {
			coeffT += a[i] + a.back();
			sum += a[i] * 1ll * a.back();
		}
		fornr(i, n - 1) {
/*			if (i == 0) {
				break;
			}*/
			ll tVal = -a[i];
			coeffT -= a[i] + a.back();
			coeffT += a[i] + a[0];
			sum -= a[i] * 1ll * a.back();
			sum += a[i] * 1ll * a[0];
			
			if (tVal * 1. * coeffT + sum > best) {
				best = max(best, tVal * coeffT + sum);
			}
		}
		cout << best << '\n';
	}
	return 0;
}