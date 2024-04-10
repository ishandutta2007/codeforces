#include <bits/stdc++.h>
using namespace std;
#define MAX 500010
#define all(v) v.begin(), v.end()
#define ln '\n'
#define MOD 10007
#define INF 2100000000
#define abs(x) ((x)>0?(x):-(x))
typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll T;
	cin >> T;
	while (T-- > 0) {
		ll q, d;
		cin >> q >> d;
		ll i, a, p;
		for (i = 1; i <= q; i++) {
			cin >> a;
			p = 1;
			if (a >= 10 * d) cout << "YES" << ln;
			else {
				while (((a % 10) != ((p*d) % 10)) && p <= 11) p++;
				if ((p*d - a) % 10)cout << "NO" << ln;
				else if (p*d > a) cout << "NO" << ln;
				else cout << "YES" << ln;
			}
		}
	}
	return 0;
}