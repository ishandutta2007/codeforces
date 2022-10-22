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

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	rep(i,0,t) {
		ll n;
		cin >> n;
		vector<ll> a(n);
		rep(j,0,n)
			cin >> a[j];
		ll ans = 0;
		rep(j,0,n-1) {
			ans = max(ans, a[j]*a[j+1]);
		}
		cout << ans << endl;
	}
}