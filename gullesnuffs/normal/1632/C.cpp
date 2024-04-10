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
	int a, b;
	cin >> a >> b;
	int ans = abs(a-b);
	rep(i,0,21) {
		int B = b + (1<<i) - (b%(1<<i));
		rep(A,a,b+1) {
			ans = min(ans, A-a+1+((A|b)-b));
			ans = min(ans, A-a+1+((A|B)-B)+(B-b));
		}
	}
	cout << ans << endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while (t--) solve();
}