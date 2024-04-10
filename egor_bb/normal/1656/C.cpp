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
		int got1 = 0;
		forn(i, n) {
			cin >> a[i];
			if (a[i] == 1) {
				got1++;
			}
		}
		if (!got1) {
			cout << "YES\n";
		} else {
			sort(all(a));
			int can = 1;
			forn(i, n - 1) {
				if (a[i] + 1 == a[i + 1]) {
					can = 0;
					break;
				}
			}
			if (can) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}
	return 0;
}