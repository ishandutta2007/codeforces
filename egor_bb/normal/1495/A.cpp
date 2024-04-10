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

const int N = 1e5 + 100;

int a[N], b[N];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cout.precision(20);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int p1 = 0, p2 = 0;
		forn(i, 2 * n) {
			int x, y;
			cin >> x >> y;
			if (x == 0) {
				a[p1++] = abs(y);
			} else {
				b[p2++] = abs(x);
			}
		}
		sort(a, a + n);
		sort(b, b + n);
		long double ans = 0;
		forn(i, n) {
			ans += sqrtl(a[i] * 1ll * a[i] + b[i] * 1ll * b[i]);
		}
		cout << fixed << ans << '\n';
		
	}
	return 0;
}