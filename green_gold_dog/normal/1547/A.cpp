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
	  ll x1, x2, x3, y1, y2, y3;
	  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	  if (x1 == x2 && x2 == x3 && y3 < max(y1, y2) && y3 > min(y1, y2)) {
	    cout << abs(y1-y2)+2 << '\n';
	    continue;
	  }
	  if (y1 == y2 && y2 == y3 && x3 < max(x1, x2) && x3 > min(x1, x2)) {
	    cout << abs(x1-x2)+2 << '\n';
	    continue;
	  }
	  cout << abs(x1-x2)+abs(y1-y2) << '\n';
	}
}