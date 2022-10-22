#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(NULL)
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define INF 1e18
#define inf 1e9
#define pb push_back
#define eb emplace_back
#define pre(a) cout<<fixed; cout.precision(a);
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int t;

void solve() {
	int b, p, f, h, c;
	cin >> b >> p >> f;
	cin >> h >> c;

	int ans = 0;

	b /= 2;
	if(h > c) {
		
		ans += min(p, b) * h;
		b -= min(p, b);
		ans += min(b, f) * c;
	}
	else {
		ans += min(f, b) * c;
		b -= min(f, b);
		ans += min(b, p) * h;
	}

	cout << ans << "\n";
}

int main() {
	fast;

	cin >> t;

	while(t--) {
		solve();
	}
}