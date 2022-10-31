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
	int n;
	cin >> n;
	vector<pii> ans;
	vector<int> q2, q3;
	forn(i, n) {
		int x;
		cin >> x;
		if (x == 0) {
			continue;
		} else if (x == 1) {
			if (sz(q2) == 0 && sz(q3) == 0) {
				ans.pb(mp(i, i));
			} else if (sz(q2) > 0) {
				int pos = q2.back();
				q2.pop_back();
				ans.pb(mp(pos, i));
			} else {
				int pos = q3.back();
				q3.pop_back();
				ans.pb(mp(pos, i));
				ans.pb(mp(i, i));
			}
		} else if (x == 2) {
			ans.pb(mp(i, i));
			if (sz(q3) > 0) {
				int pos = q3.back();
				q3.pop_back();
				ans.pb(mp(pos, i));
			}
			q2.pb(i);
		} else {
			ans.pb(mp(i, i));
			if (sz(q3) > 0) {
				int pos = q3.back();
				q3.pop_back();
				ans.pb(mp(pos, i));
			}
			q3.pb(i);
		}
	}
	if (sz(q2) > 0 || sz(q3) > 0) {
		cout << -1 << '\n';
	} else {
		cout << sz(ans) << '\n';
		for (auto p : ans) {
			cout << p.fst + 1 << " " << p.snd + 1 << '\n';
		}
	}
	
    return 0;
}