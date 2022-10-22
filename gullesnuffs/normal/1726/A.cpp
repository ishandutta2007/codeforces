#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int lo = 1e9;
	int hi = 0;
	int ans = -1000;
	rep(i,0,n) {
		cin >> a[i];
		lo = min(lo, a[i]);
		hi = max(hi, a[i]);
	}
	rep(i,0,n) {
		ans = max(ans, (a[i]-a[(i+1)%n]));
	}
	ans = max(ans, hi - a[0]);
	ans = max(ans, a[n-1] - lo);
	cout << ans << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	while (T--)
		solve();
}