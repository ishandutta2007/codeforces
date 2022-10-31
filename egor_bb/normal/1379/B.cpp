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
	int t;
	cin >> t;
	while(t--) {
		ll l, r, m;
		cin >> l >> r >> m;
		ll minM = m - (r - l);
		ll maxM = m - (l - r);
	//	cout << minM << " " << maxM << '\n';
		forab(a, l, r + 1) {
			ll n = (minM + a - 1) / a;
			if (n <= 0) n = 1;
	//		cerr << n << '\n';
			ll nextVal = n * a;
		//	cout << n << " " << nextVal << " !" << '\n';
			if (nextVal <= maxM) {
				forab(b, l, r + 1) {
					ll c = -(m - b - nextVal);
			//		cerr << c << '\n';
					if (l <= c && c <= r) {
						cout << a << " " << b << " " << c << '\n';
						break;
					}
				}
				break;
			}
		}
	}
	
    return 0;
}