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
		vi a(n), b(n);
		forn(i, n) {
			cin >> a[i] >> b[i];
		}
		int l = 0, r = n + 1;
		while(r - l > 1) {
			int m = (l + r) / 2;
			int got = 0;
			forn(i, n) {
				if (b[i] >= got && got + 1 + a[i] >= m) {
					got++;
				}
			}
			if (got >= m) {
				l = m;
			} else {
				r = m;
			}
		}
		cout << l << '\n';
		
	}
	return 0;
}