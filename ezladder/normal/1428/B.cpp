#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {
	string s;
	cin >> s >> s;
	int w1 = 0, w2 = 0;
	for (int i = 0; i < s.size(); ++i) {
		char c = s[i];
		int j = i + 1;
		if (j == s.size()) j = 0;
		if (c == '-') {
		} else if (c == '<') {
			w1 = 1;
		} else {
			w2 = 1;
		}
	}
	int ans = 0;

	if (w1 + w2 <= 1) {
		ans = s.size();
	} else {
		for (int i = 0; i < s.size(); ++i) {
			int j = i - 1;
			if (j < 0) j += s.size();
			if (s[i] == '-' || s[j] == '-') ++ans;
		}
	}

	cout << ans << "\n";
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}