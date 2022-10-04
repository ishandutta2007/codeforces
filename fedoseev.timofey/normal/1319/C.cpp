#include  <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	for (char c = 'z'; c >= 'a'; --c) {
	 	bool fnd = true;
	 	while (fnd) {
	 		fnd = false;
	 		for (int i = 0; i < (int)s.size(); ++i) {
	 			if (s[i] == c && i > 0 && s[i - 1] + 1 == s[i]) {
	 				fnd = true;
	 				++ans;
	 				s.erase(s.begin() + i);
	 				break;
	 			}
	 			if (s[i] == c && i + 1 < (int)s.size() && s[i + 1] + 1 == s[i]) {
	 				fnd = true;
	 				++ans;
	 				s.erase(s.begin() + i);
	 				break;
	 			}
	 		}
  	}
	}
	//cout << s << endl;
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}	
}