#include <bits/stdc++.h> 
 
using namespace std;
 
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << '\n';
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
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		ll ans = 0;
		vector<int> vals;
		forn(i, n) {
			int x;
			cin >> x;
			vals.pb(x);
			if (x < 0) {
				ans += x;
			}
		}
		sort(all(vals));
		if (!vals.empty()) {
			if (vals.back() > 0) {
				ans += vals.back();
			}
			ll curSum = vals.back(), cnt = 1;
			fornr(i, sz(vals) - 1) {
				ans += vals[i] * 1ll * cnt - curSum;
				cnt++;
				curSum += vals[i];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}