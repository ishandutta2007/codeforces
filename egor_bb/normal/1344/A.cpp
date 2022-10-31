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

const int N = 2e5 + 100;


int cnt[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	forn(tt, t) {
		int n;
		cin >> n;
		forn(i, n) cnt[i] = 0;
		forn(i, n) {
			int x;
			cin >> x;
			x += i;
			x = ((x % n) + n) % n;
			cnt[x]++;
		}
		int ok = 1;
		forn(i, n) {
			if (cnt[i] != 1) {
				ok = 0;
				break;
			}
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
	
    return 0;
}