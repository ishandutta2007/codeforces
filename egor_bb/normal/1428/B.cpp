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
		int n;
		cin >> n;
		string s;
		cin >> s;
		int got1 = 0, got2 = 0;
		forn(i, n) {
			if (s[i] == '<') got1 = 1;
			if (s[i] == '>') got2 = 1;
		}
		if (got1 == 0 || got2 == 0) {
			cout << n << '\n';
		} else {
			int cnt = 0;
			forn(i, n) {
				int nxt = (i + 1) % n;
				if (s[i] == '-' || s[nxt] == '-') cnt++;
			}
			cout << cnt << '\n';
		}
	}
	
    return 0;
}