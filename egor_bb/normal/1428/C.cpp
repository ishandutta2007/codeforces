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
		string s;
		cin >> s;
		vector<pii> cnt;
		for(char c : s) {
			int x = c - 'A';
			if (sz(cnt) == 0 || cnt.back().snd != x) {
				cnt.pb(mp(1, x));
			} else {
				cnt.back().fst++;
			}
		}
		int ans = 0;
		while(sz(cnt)) {
			int back = cnt.back().snd;
			int cntBack = cnt.back().fst;
			if (back == 0) {
				ans += cntBack;
				cnt.pop_back();
			} else {
				if (sz(cnt) >= 2) {
					int cntPrev = cnt[sz(cnt) - 2].fst;
					if (cntPrev >= cntBack) {
						cnt[sz(cnt) - 2].fst -= cntBack;
						cnt.pop_back();
					} else {
						cnt[sz(cnt) - 2].fst = 0;
						cntBack -= cntPrev;
						cnt.pop_back();
						cnt.pop_back();
						if (sz(cnt) == 0) {
							ans += (cntBack % 2);
						} else {
							cnt.back().fst += cntBack;
						}
					}
				} else {
					ans += (cntBack % 2);
					cnt.pop_back();
				}
			}
		}
		cout << ans << '\n';
		
	}
	
    return 0;
}