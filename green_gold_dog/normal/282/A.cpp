#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, cnt = 0;
	cin >> n;
	for (ll i = 0; i < n; i++) {
	  string s;
	  cin >> s;
	  if (s[1] == '+') {
	    cnt++;
	  } else {
	    cnt--;
	  }
	}
	cout << cnt;
}