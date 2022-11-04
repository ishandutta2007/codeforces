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
    string s;
    cin >> s;
    ll ans = 0;
    for (auto i : s) {
      ans = max(ans, (ll)(i-'0'));
    }
    cout << ans << '\n';
  }
}