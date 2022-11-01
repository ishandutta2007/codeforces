// July 26, 2018
// http://codeforces.com/contest/1011/problem/A

/*

*/


#include <bits/stdc++.h>

using namespace std;


int N, K;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG)


	cin >> N >> K >> s;
	sort(s.begin(), s.end());
	int cur = -2, used = 0;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (s[i] - 'a' - cur < 2) continue;
		ans += s[i] - 'a' + 1;
		cur = s[i] - 'a';
		used++;
		if (used == K) {
			cout << ans << '\n';
			return 0;
		}
	}
	cout << "-1\n";


	return 0;
}