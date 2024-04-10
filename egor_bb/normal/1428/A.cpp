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
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2 || y1 == y2) {
			cout << abs(x1 - x2) + abs(y1 - y2) << '\n';
		} else {
			cout << abs(x1 - x2) + abs(y1 - y2) + 2 << '\n';
		}
	}
	
    return 0;
}