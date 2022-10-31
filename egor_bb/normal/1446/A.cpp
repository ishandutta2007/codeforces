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

const int N = 2e5 + 100;

ll a[N];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		ll n, w;
		cin >> n >> w;
		forn(i, n) {
			cin >> a[i];
		}
		int got = 0;
		vector<int> items; 
		forn(i, n) { 
			if (a[i] <= w && a[i] * 2 >= w) {
				got = 1;
				items.pb(i + 1);
				got = 1;
				break;
			}
		}
		if (!got) {
			ll sum = 0;
			forn(i, n) {
				if (sum + a[i] <= w) {
					sum += a[i];
					items.pb(i + 1);
				}
			}
			if (sum * 2 >= w) {
				got = 1;
			}
		}
		if (got) {
			cout << sz(items) << '\n';
			for(int x : items) {
				cout << x << " ";
			}
			cout << '\n';
		} else {
			cout << -1 << '\n';
		}
	}
	return 0;
}