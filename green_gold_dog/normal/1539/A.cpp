#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll g;
	cin >> g;
	for (ll _ = 0; _ < g; _++) {
	  ll n, x, t;
	  cin >> n >> x >> t;
	  ll  col = min(t/x, n-1);
	  cout << col*n-(col*(col+1)/2) << '\n';
	}
}