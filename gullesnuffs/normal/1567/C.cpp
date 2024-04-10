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
	string n;
	cin >> n;
	reverse(all(n));
	int m = sz(n);
	ll ans = -2;
	rep(carry,0,1<<m) {
		if (m >= 1 && (carry&(1<<(m-1))))
			continue;
		if (m >= 2 && (carry&(1<<(m-2))))
			continue;
		ll ways = 1;
		rep(i,0,m) {
			int target = n[i]-'0';
			if (carry&(1<<i))
				target += 10;
			if (i >= 2 && (carry&(1<<(i-2))))
				--target;
			if (target < 0 || target >= 19) {
				ways = 0; 
				continue;
			}
			ways *= 10-abs(9-target);
		}
		ans += ways;
		/*if (ways) {
			cerr << carry << " " << ways << endl;
		}*/
	}
	cout << ans << endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	while (T--)
		solve();
}