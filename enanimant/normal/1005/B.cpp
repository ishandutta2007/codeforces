#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG)

	string s, t;
	cin >> s >> t;

	int sl = s.length(), tl = t.length();
	int num_eq = -1;
	for (int i = 0; i < min(sl, tl); i++) {
		if (s[sl - 1 - i] != t[tl - 1 - i]) {
			num_eq = i;
			break;
		}
	}

	int ans = -1;
	if (num_eq == -1) {
		ans = abs(sl - tl);
	} else {
		ans = sl + tl - 2 * num_eq;
	}
	assert(ans != -1);

	cout << ans << '\n';


	return 0;
}