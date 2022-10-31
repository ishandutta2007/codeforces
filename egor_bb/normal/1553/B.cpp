#include <bits/stdc++.h> 
 
using namespace std;
 
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
}

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
	int q;
	cin >> q;
	while(q--) {
		string s, t;
		cin >> s >> t;
		int ok = 0;
		forn(i, sz(s)) {
			forn(j, sz(s) - i) {
				if (s[i + j] != t[j]) {
					break;
				}
				int l1 = j + 1;
				int l2 = sz(t) - l1;
				int k = i + j - l2;
				if (k < 0) {
					continue;
				}
				int cur = j + 1;
				int localOk = 1;
				for(int pos = i + j - 1; pos >= k; pos--, cur++) {
					if (t[cur] != s[pos]) {
						localOk = 0;
						break;
					}
				}
				if (localOk) {
					ok = 1;
					break;
				}
			}
			if (ok) {
				break;
			}
		}
		if (ok) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}	
	return 0;
}