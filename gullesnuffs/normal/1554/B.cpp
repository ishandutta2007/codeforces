#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(ll i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	rep(l,0,t) {
		ll n, k;
		cin >> n >> k;
		vector<ll> a(n);
		rep(j,0,n)
			cin >> a[j];
		ll ans = -1e9;
		rrep(i,n+1,1)
		rrep(j,i,1) {
			if (i*j < ans)
				break;
			ll val = i*j-k*(a[i-1]|a[j-1]);
			ans = max(ans, val);
		}
		cout << ans << endl;
	}
}