#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int pos1 = -INF, pos2 = -INF, pos3 = -INF;
		int ans = INF;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '1') pos1 = i;
			if (s[i] == '2') pos2 = i;
			if (s[i] == '3') pos3 = i;
			int left = min({ pos1, pos2, pos3 });
			ans = min(ans, i - left + 1);
		}
		if (ans == INF) ans = 0;
		cout << ans << '\n';
	}
	return 0;
}