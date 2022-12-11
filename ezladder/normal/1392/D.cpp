#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;


int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		string s;
		cin >> s >> s;
		vector<pair<int, char>> t;
		int len = 1;
		char c = s[0];
		for (int i = 1; i < s.size(); ++i) {
			if (s[i] == c) {
				++len;
			} else {
				t.pb({len, c});
				len = 1;
				c = s[i];
			}
		}
		t.pb({len, c});
		if (t.size() > 1) {
			if (t[0].y == t.back().y) {
				t[0].x += t.back().x;
				t.pop_back();
			}
		}
		int ans = 0;

		if (t.size() == 1) {

			int n = s.size();
			if (n >= 3) {
				n--;
				ans++;
				ans += n / 3;
			}

		} else {

			for (auto [w1, w2] : t) if (w1 >= 3) {
				ans += w1 / 3;
			}
		}

		cout << ans << "\n";
	}

}