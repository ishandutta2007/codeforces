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
	string s1 = s, s2 = s;
	transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
	transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
	ll ans = 0;
	for (ll i = 0; i < s.size(); i++) {
	  ans += s1[i] != s[i];
	}
	if (ans <= s.size() / 2) {
	  cout << s1;
	} else {
	  cout << s2;
	}
}

/*
















*/