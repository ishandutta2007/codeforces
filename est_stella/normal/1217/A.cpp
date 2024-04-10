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
	ll s, i, e;
	cin >> s >> i >> e;

	ll ans = (e + s) - max(s-1, (i+e+s)/2);
	cout << max(0LL, ans) << "\n";
}

int main() {
	fast;

	int t;
	cin >> t;

	while(t--) {
		solve();
	}
}