#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

int solve(string S) {
	int len = 0;
	int ans = 0;
	for (int i = 0; i + 1 < S.size(); i++) {
		bool b = S[i] != S[i + 1];
		if (b)
			++len;
		else
			len = 0;
		ans = max(ans, len + 1);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	string s;
	cin >> s;
	cout << min((int) s.size(), solve(s + s)) << endl;

	cout.flush();
	return 0;
}