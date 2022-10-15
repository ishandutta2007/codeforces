#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

int T;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> T;
	while (T--) {
		string s; cin >> s;
		sort(s.begin(), s.end());
		if (s.front() == s.back()) {
			cout << -1 << '\n';
		}
		else cout << s << '\n';
	}

	cout.flush();
	return 0;
}