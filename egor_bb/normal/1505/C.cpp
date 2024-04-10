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
	string s;
	while(cin >> s) {
		int n = sz(s);
		forn(i, n) s[i] -= 'A';
		int ok = 1;
		forab(i, 2, n) {
			if ((s[i - 1] + s[i - 2]) % 26 != s[i]) {
				ok = 0;
			}
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}