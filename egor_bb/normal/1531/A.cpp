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
	string s = "blue";
	int n;
	cin >> n;
	int locked = 0;
	forn(i, n) {
		string t;
		cin >> t;
		if (t == "lock") {
			locked = 1;
		} else if (t == "unlock") {
			locked = 0;
		} else if (!locked) {
			s = t;
		}
	}	
	cout << s << '\n';
	return 0;
}