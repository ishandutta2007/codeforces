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

string reff = "abacaba";

int cnt(string &s) {
	int ans = 0;
	forn(i, sz(s)) {
		if (i + sz(reff)	> sz(s)) break;
		int ok = 1;
		forn(j, sz(reff)) {
			if (s[i + j] != reff[j]) {
				ok = 0;
				break;
			}
		}
		ans += ok;
	}
	return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		bool can = false;
		string tmp;
		forn(i, n - sz(reff) + 1) {
			tmp = s;
			forn(j, sz(reff)) {
				if (tmp[i + j] == '?') {
					tmp[i + j] = reff[j];
				}
			}
			forn(j, n) {
				if (tmp[j] == '?') {
					tmp[j] = 'z';
				}
			}
			if (cnt(tmp) == 1) {
				can = true;
				break;
			}
		}
		if (can) {
			cout << "Yes\n";
			cout << tmp << '\n';
		} else {
			cout << "No\n";
		}
	}
	
    return 0;
}