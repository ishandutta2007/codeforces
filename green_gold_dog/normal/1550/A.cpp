#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
	  ll n;
	  cin >> n;
	  ll col = 0, nown = 1;
	  while (nown <= n) {
	    col++;
	    n -= nown;
	    nown += 2;
	  }
	  cout << col + (n > 0) << '\n';
	}
}