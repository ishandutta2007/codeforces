#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	set<char> c;
	for (char C : s)
		c.insert(C);
	puts(sz(c) == sz(s) ? "YES" : "NO");
	/*if (sz(s) > 10) {
		cout << "NO" << endl;
	} else {
		sort(all(s));
		do {
			bool ok = true;
			rep(len,2,sz(s)+1) {
				rep(i,0,sz(s)-len) {
					bool pal = true;
					rep(j,0,len) {
						if (s[i+j] != s[i+len-1-j])
							pal = false;
					}
					if (pal)
						ok = false;
				}
			}
			if (ok) {
				cout << "YES" << endl;
				return;
			}
		} while(next_permutation(all(s)));
				cout << "NO" << endl;
				return;
	}*/
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while (t--)
		solve();
}