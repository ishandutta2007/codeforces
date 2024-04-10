#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0);
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define eb emplace_back
#define pb push_back
#define pre(a) cout<<fixed; cout.precision(a);

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;

int solve() {
	int n, x;
	cin >> n >> x;

	int d[111], h[111], t[111];
	int mx = -1, mn = inf*2;

	for(int i=1; i<=n; i++) {
		cin >> d[i] >> h[i];
		mx = max(mx, d[i]);
		mn = min(mn, -d[i] + h[i]);
	}

	if(x <= mx) {
		cout << 1 << "\n";
		return 0;
	}

	if(mn >= 0) {
		cout << -1 << "\n";
		return 0;
	}

	cout << (x - mx - 1) / -mn + 2 << "\n";
}

int main() {
	fast;

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}