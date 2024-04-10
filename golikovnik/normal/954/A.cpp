#include <bits/stdc++.h>

using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	string s;
	cin >> n >> s;
	int cnt = 0;
	int i = 0;
	while (i < n) {
		if (i + 1 < n) {
			if (s[i] == 'R' and s[i + 1] == 'U' or s[i] == 'U' and s[i + 1] == 'R') {
				i += 2;
				++cnt;
				continue;
			}
		}
		++cnt, ++i;
	}
	cout << cnt << '\n';
	return 0;
}