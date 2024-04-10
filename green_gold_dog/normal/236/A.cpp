#include <bits/stdc++.h>
typedef long long ll;
 
using namespace std;
 
const ll INF = 1'000'000'000'000'000;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	ll ans = 0;
	for (ll i = 1; i < s.size(); i++) {
	  if (s[i] != s[i - 1]) {
	    ans++;
	  }
	}
	cout << (ans % 2 == 0 ? "IGNORE HIM!" : "CHAT WITH HER!");
}
 
/*
















*/