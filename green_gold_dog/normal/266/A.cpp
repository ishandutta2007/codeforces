#include <bits/stdc++.h>
typedef long long ll;
 
using namespace std;
 
const ll INF = 1'000'000'000'000'000;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	string s;
	cin >> s;
	ll ans = 0;
	for (ll i = 1; i < s.size(); i++) {
	  if (s[i] == s[i - 1]) {
	    ans++;
	  }
	}
	cout << ans;
}
 
/*
















*/