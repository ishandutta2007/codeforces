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

const int N = 105;

char symb[N];
int f[N][N];
char ans[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	forn(i, 26) {
		symb[i] = char('a' + i);
	}
	forn(i, 26) {
		symb[26 + i] = char('A' + i);
	}
	forn(i, 10) {
		symb[52 + i] = char('0' + i);
	}
	while(t--) {
		int r, c, k, total = 0;
		cin >> r >> c >> k;
		forn(i, r) {
			string s;
			cin >> s;
			forn(j, c) {
				f[i][j] = (s[j] == 'R');
				total += f[i][j];
			}
		}
		vector<int> got;
		int mn = total / k, big = total % k;
		forn(i, k) {
			if (i < big) got.pb(mn + 1);
			else got.pb(mn);
		}
		int x = 0, y = 0, add = 1, curChicken = 0, gotNow = 0;
		while(x < r) {
			if (f[x][y]) {
				gotNow++;
				if (gotNow > got[curChicken]) {
					curChicken++;
					gotNow = 1;
				}
			}
			ans[x][y] = symb[curChicken];
			if (add == 1 && y == c - 1) {
				add = -1;
				x++;
			} else if (add == -1 && y == 0) {
				add = 1;
				x++;
			} else {
				y += add;
			}
		}
		forn(i, r) {
			forn(j, c) {
				cout << ans[i][j];
			}
			cout << '\n';
		}
	}
	
    return 0;
}